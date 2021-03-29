"""!
    @brief Compiles M4 files

    @note Use <command> --help to see the command line options
"""

import argparse
import subprocess
from glob import glob
from os import remove, chdir, getcwd
from os.path import join, isfile, abspath, isdir, realpath, dirname
from shutil import copyfile


def dos2unix(filename):
    """!
        @brief Converts DOS file endings to Unix file endings

        @param[in] input_file str: path and name of the input file
    """
    text = open(filename, 'rb').read().replace(b"\r\n", b"\n")
    open(filename, 'wb').write(text)


def unix2dos(filename):
    """!
        @brief Converts Unix file endings to DOS file endings

        @param[in] input_file str: path and name of the input file
    """
    text = open(filename, 'rb').read().replace(b"\r\n", b"\n").replace(b"\n", b"\r\n")
    open(filename, 'wb').write(text)


def run_m4(args, input_file, output_file, m4_command="m4"):
    """!
        @brief Runs the GNU M4 command

        @param[in] args list: arguments for M4
        @param[in] input_file str: path and name of the input M4 file
        @param[in] input_file str: path and name of the output file
        @param[in] m4_command str: command to run GNU M4
    """
    if not isfile(input_file):
        print("File {} not found".format(input_file))
        return
    if isfile(output_file):
        remove(output_file)
    arguments = [m4_command]
    arguments += args
    script_path = abspath(dirname(realpath(__file__)))
    cwd = abspath(getcwd())
    chdir(script_path)
    process = subprocess.Popen(" ".join(arguments), cwd=abspath("."), stdin=subprocess.PIPE, stdout=subprocess.PIPE) # , stdout=subprocess.PIPE
    chdir(cwd)
    with open(input_file, "rb") as file:
        result = process.communicate(file.read())
        return_code = process.wait()
        if return_code == 0:
            with open(output_file, "wb") as file:
                file.write(result[0])
        else:
            print("M4 returned error {} while processing file {}".format(return_code, input_file.replace("__.m4", ".m4")))
            if return_code == 1 and len(result[0]) > 0:
                with open(output_file, "wb") as file:
                    file.write(result[0])
            return


def compile_m4_dep(filename, m4_defs_path, includes, generate_cpp_file=True):
    """!
        @brief Compiles a *Dep.m4 file

        @param[in] filename str: path and name of the M4 file
        @param[in] m4_defs_path str: path to the M4 definition files
        @param[in] includes list: additional include paths
        @param[in] generate_cpp_file bool: generate a C++ wrapper file
    """
    if not isfile(filename):
        print("File {} not found".format(filename))
        return
    implementation_m4_filename = "Implementation.m4"
    implementation_m4_file = join(m4_defs_path, implementation_m4_filename)
    if not isfile(implementation_m4_file):
        print("File {} not found".format(implementation_m4_file))
        return
    include_args = []
    for include_path in includes:
        if isdir(include_path) and not abspath(include_path) in include_args:
            include_args += ["-I", abspath(include_path)]
    temp_filename = filename.rpartition(".")[0] + "__.m4"
    header_filename = filename.rpartition(".")[0] + ".h"
    copyfile(filename, temp_filename)
    dos2unix(temp_filename)
    run_m4(include_args + ["-I", m4_defs_path, implementation_m4_filename, "-"], temp_filename, header_filename)
    if isfile(header_filename):
        unix2dos(header_filename)
    else:
        print("Output file {} not found".format(header_filename))
    if generate_cpp_file:
        cpp_wrapper_m4_filename = "C++Wrapper.m4"
        cpp_wrapper_m4_file = join(m4_defs_path, cpp_wrapper_m4_filename)
        if not isfile(cpp_wrapper_m4_file):
            print("File {} not found".format(cpp_wrapper_m4_file))
            return
        cpp_filename = filename.rpartition("Dep.")[0] + ".cpp"
        run_m4(include_args + ["-I", m4_defs_path, cpp_wrapper_m4_filename, "-"], temp_filename, cpp_filename)
        if isfile(cpp_filename):
            dos2unix(cpp_filename)
        else:
            print("Output file {} not found".format(cpp_filename))
    remove(temp_filename)


def compile_m4_itf(filename, m4_defs_path):
    """!
        @brief Compiles a *Itf.m4 file

        @param[in] filename str: path and name of the M4 file
        @param[in] m4_defs_path str: path to the M4 definition files
    """
    exports_m4_filename = "Exports.m4"
    if not isfile(filename):
        print("File {} not found".format(filename))
        return
    exports_m4_file = join(m4_defs_path, exports_m4_filename)
    if not isfile(exports_m4_file):
        print("File {} not found".format(exports_m4_file))
        return
    temp_filename = filename.rpartition(".")[0] + "__.m4"
    header_filename = filename.rpartition(".")[0] + ".h"
    copyfile(filename, temp_filename)
    dos2unix(temp_filename)
    run_m4(["-I", m4_defs_path, exports_m4_filename, "-"], temp_filename, header_filename)
    if isfile(header_filename):
        unix2dos(header_filename)
    else:
        print("Output file {} not found".format(header_filename))
    remove(temp_filename)


def compile_m4(filename, m4_defs_path="", generate_cpp_file=True):
    """!
        @brief Compiles the given M4 file

        @param[in] filename str: path and name of the M4 file
        @param[in] m4_defs_path str: path to the M4 definition files
        @param[in] generate_cpp_file bool: generate a C++ wrapper file
    """
    filename = abspath(filename)
    m4_defs_path = abspath(m4_defs_path)
    script_path = abspath(dirname(realpath(__file__)))
    if m4_defs_path == "":
        m4_defs_path = abspath(join(script_path, "../M4Defs"))
    if not isfile(filename):
        print("File {} not found".format(filename))
        return
    if filename.endswith("Itf.m4"):
        compile_m4_itf(filename, m4_defs_path)
    elif filename.endswith("Dep.m4"):
        includes = [abspath(dirname(filename)), abspath(join(dirname(filename), "../")), abspath(join(script_path, "../../../Components"))]
        compile_m4_dep(filename, m4_defs_path, includes, generate_cpp_file)
    else:
        print("File {} not supported (Does not end with 'Itf.m4' or 'Dep.m4')".format(filename))


def compile_all_m4(dir, m4_defs_path="", compile_itf=True, compile_dep=True, generate_cpp_file=True):
    """!
        @brief Compiles all M4 files in a directory. Supports wildcards.

        @param[in] dir str: directory path or wildcard
        @param[in] m4_defs_path str: path to the M4 definition files
        @param[in] compile_itf bool: compile *Itf.m4 files
        @param[in] compile_dep bool: compile *Dep.m4 files
        @param[in] generate_cpp_file bool: generate a C++ wrapper file
    """
    if "*" in dir:
        for file in glob(dir):
            if (file.endswith("Itf.m4") and compile_itf) or (file.endswith("Dep.m4") and compile_dep):
                compile_m4(file, m4_defs_path, generate_cpp_file)
    elif isdir(dir):
        if compile_itf:
            for file in glob(abspath(join(dir, "*Itf.m4"))):
                compile_m4(file, m4_defs_path, generate_cpp_file)
        if compile_dep:
            for file in glob(abspath(join(dir, "*Dep.m4"))):
                compile_m4(file, m4_defs_path, generate_cpp_file)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compiles M4 files")
    parser.add_argument('path', nargs="+", help="Input *[Itf|Dep].m4 file or directory of M4 files, supports wildcards")
    parser.add_argument("-m", "--m4_defs_path", nargs=1, type=str, default="", help="Path to the M4 definition files")
    parser.add_argument("-a", "--all", help="Compile all files in the given directory", action="store_true", default=False, required=False)
    parser.add_argument("-i", "--disable_itf", help="Do not compile *Itf.m4 files", action="store_true", default=False, required=False)
    parser.add_argument("-d", "--disable_dep", help="Do not compile *Dep.m4 files", action="store_true", default=False, required=False)
    parser.add_argument("-n", "--no_cpp_file", help="Do not generate a C++ wrapper file for *Dep.m4 files", action="store_true", default=False, required=False)
    args = parser.parse_args()
    m4_defs_path = abspath(join(dirname(realpath(__file__)), "../M4Defs"))
    if not args.m4_defs_path == "" and isdir(args.m4_defs_path[0]):
        m4_defs_path = abspath(args.m4_defs_path[0])
    for path in args.path:
        if "*" in path:
            compile_all_m4(abspath(path), m4_defs_path, not args.disable_itf, not args.disable_dep, not args.no_cpp_file)
        elif isdir(path):
            if args.all:
                compile_all_m4(abspath(path), m4_defs_path, not args.disable_itf, not args.disable_dep, not args.no_cpp_file)
            else:
                print("Warning: Directory given. Use -a to compile all m4 files.")
        elif (path.endswith("Itf.m4") and not args.disable_itf) or (path.endswith("Dep.m4") and not args.disable_dep):
            compile_m4(abspath(path), m4_defs_path, (not args.no_cpp_file))

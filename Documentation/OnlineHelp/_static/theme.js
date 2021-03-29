$(document).ready(function(){
    $('.toctree-wrapper li > ul').parent().addClass("parent")
    $('.toctree-wrapper li > ul').hide();
    $('.toctree-wrapper li > ul').parent().prepend("<button></button>")
    $('.toctree-wrapper button').click(function() {
        $(this).parent().children('ul').slideToggle();
        $(this).toggleClass("expanded");
    });
});
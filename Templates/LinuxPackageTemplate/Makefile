ARCHITECTURE?=armhf
PACKAGE_VERSION?=3.5.16.0
PACKAGE=codesyscontrol_V${PACKAGE_VERSION}_${ARCHITECTURE}.deb
PACKAGE_DESCRIPTION=V${PACKAGE_VERSION}, $(shell date)
MAINTAINER?=Maintainer

${PACKAGE}:
	rm -rf debian_pack && cp -pRTf debian/ debian_pack/
	sed -i "/Version:/ s,^.*$$,Version: ${PACKAGE_VERSION},g" debian_pack/DEBIAN/control
	sed -i "/Architecture:/ s/^.*$$/Architecture: ${ARCHITECTURE}/g" debian_pack/DEBIAN/control
	sed -i "/Maintainer:/ s/^.*$$/Maintainer: ${MAINTAINER}/g" debian_pack/DEBIAN/control
	sed -i "/Description:/ s/^.*$$/Description: ${PACKAGE_DESCRIPTION}/g" debian_pack/DEBIAN/control
	dpkg-deb --root-owner-group --build -Zgzip debian_pack/ ${PACKAGE}
	#rm -rf debian_pack/
	@echo "Built debian package $@"

.PHONY: clean
clean:
	rm -rf *.deb
	rm -rf debian_pack/

.PHONY: package
package: ${PACKAGE}

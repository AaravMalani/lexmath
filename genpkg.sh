set -e
rm -rf build /tmp/lexmathwork/* *.deb *.rpm
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/lexmathwork/usr/local/ -DDO_NOT_LDCONFIG=true
cd build
make install 
cd ..
mkdir -p /tmp/lexmathwork/DEBIAN/
cp DEBIAN_CONTROL /tmp/lexmathwork/DEBIAN/control
dpkg-deb --build --root-owner-group /tmp/lexmathwork
cp /tmp/lexmathwork.deb .
VERSION=$(cat DEBIAN_CONTROL | grep Version: | sed -e 's/Version: //')
NAME=$(cat DEBIAN_CONTROL | grep Package: | sed -e 's/Package: //')
ARCH=$(cat DEBIAN_CONTROL | grep Architecture: | sed -e 's/Architecture: //')
mv lexmathwork.deb $NAME-$VERSION-$ARCH.deb
fakeroot alien -r $NAME-$VERSION-$ARCH.deb
mv *.rpm $NAME-$VERSION-$ARCH.rpm
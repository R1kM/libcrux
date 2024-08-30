#!/usr/bin/env bash

set -v -e -x

curl https://sh.rustup.rs -sSf | bash -s -- -y

# Prepare the sources
opam init --bare --disable-sandboxing --shell-setup --yes
opam switch create 4.14.1

# Get F*, HACL*, Charon, Karamel, Eurydice for running proofs and extraction
curl -L https://github.com/FStarLang/FStar/releases/download/v2024.01.13/fstar_2024.01.13_Linux_x86_64.tar.gz \
    --output Fstar.tar.gz
tar --extract --file Fstar.tar.gz
rm -f Fstar.tar.gz

curl -L https://github.com/FStarLang/binaries/raw/master/z3-tested/z3-4.8.5-x64-ubuntu-16.04.zip --output z3.zip
unzip z3.zip
rm -rf z3.zip
mv z3-4.8.5-x64-ubuntu-16.04/ z3

curl -L https://github.com/hacl-star/hacl-star/archive/2a8b61343a1a7232611cb763b0dc3e4dff84d656.zip \
    --output hacl-star.zip
unzip hacl-star.zip
rm -rf hacl-star.zip
mv hacl-star-2a8b61343a1a7232611cb763b0dc3e4dff84d656/ hacl-star

curl -L https://github.com/AeneasVerif/charon/archive/6b5e110342a771a3e1c739b10294b1778e4be8b4.zip \
    --output charon.zip
unzip charon.zip
rm -rf charon.zip
mv charon-6b5e110342a771a3e1c739b10294b1778e4be8b4/ charon


curl -L https://github.com/FStarLang/karamel/archive/3205d3365ea2790b02368f79fcee38e38d0b5908.zip \
    --output karamel.zip
unzip karamel.zip
rm -rf karamel.zip
mv karamel-3205d3365ea2790b02368f79fcee38e38d0b5908/ karamel

curl -L https://github.com/AeneasVerif/eurydice/archive/31be7d65ca5d6acdacfb33652e478d24dd85c1cb.zip \
    --output eurydice.zip
unzip eurydice.zip
rm -rf eurydice.zip
mv eurydice-31be7d65ca5d6acdacfb33652e478d24dd85c1cb/ eurydice

echo "export FSTAR_HOME=$HOME/fstar" >>$HOME/.profile
echo "export HACL_HOME=$HOME/hacl-star" >>$HOME/.profile
echo "export KRML_HOME=$HOME/karamel" >>$HOME/.profile
echo "export EURYDICE_HOME=$HOME/eurydice" >>$HOME/.profile
echo "export CHARON_HOME=$HOME/charon" >>$HOME/.profile
echo "export HAX_HOME=$HOME/hax" >>$HOME/.profile
echo "export PATH=\"${PATH}:$HOME/fstar/bin:$HOME/z3/bin\"" >>$HOME/.profile
echo "[[ ! -r /home/$USER/.opam/opam-init/init.sh ]] || source /home/$USER/.opam/opam-init/init.sh  > /dev/null 2> /dev/null" >>$HOME/.profile

source $HOME/.profile
opam install --yes ocamlfind visitors menhir ppx_deriving_yojson core_unix sedlex wasm fix process pprint zarith yaml easy_logging terminal
eval $(opam env)

# Build everything
cd karamel
make -j
cd -

cd charon
make -j
cd -

cd eurydice/lib
rm -f charon
ln -s $CHARON_HOME/charon-ml charon
rm -f krml
ln -s $KRML_HOME/lib krml
cd ../
make -j
cd ../

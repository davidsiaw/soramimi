docker build . -t davidsiaw/soramimitest
cd .. &&  docker run --rm -ti -v $PWD:/src --workdir=/src -u `id -u`  davidsiaw/soramimitest make

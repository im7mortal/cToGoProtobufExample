# Created by Petr Lozhkin on 8/17/18.
# Copyright (c) 2015-2025 STURFEE INC ALL RIGHTS RESERVED

FROM ubuntu:16.04

# Install dependencies.
RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates \
        cmake \
        git \
        libatlas-base-dev \
        libboost-all-dev \
        libgflags-dev \
        libgoogle-glog-dev \
        libhdf5-dev \
        libprotobuf-dev \
        pkg-config \
        protobuf-compiler \
        python-yaml \
        python-six \
        wget && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y --no-install-recommends g++

RUN apt-get install  -y --no-install-recommends  autoconf automake libtool curl make g++ unzip

RUN  git clone https://github.com/protocolbuffers/protobuf.git && \
    cd protobuf && \
    git submodule update --init --recursive && \
    ./autogen.sh && \
    ./configure CXXFLAGS="" && \
    make -j"$(nproc)" && \
    make install  && \
    ldconfig

RUN apt-get install -y python-setuptools
RUN cd protobuf/python; python setup.py install

# Install golang
ENV GOLANG_VERSION 1.8.1
RUN wget -O - https://storage.googleapis.com/golang/go${GOLANG_VERSION}.linux-amd64.tar.gz \
    | tar -v -C /usr/local -xz
ENV GOPATH /go
ENV PATH $GOPATH/bin:/usr/local/go/bin:$PATH

RUN go get -u github.com/golang/protobuf/protoc-gen-go

WORKDIR /go/src/github.com/im7mortal/cToGoProtobufExample

COPY . .

# Remove all protobuf files from host
RUN find . -name "*.pb.*" -type f -delete && find . -name "*_pb2.py" -type f -delete

# Generate CPP
RUN protoc --cpp_out=src/. params.proto && mv src/params.pb.h include/params.pb.h

RUN g++ -c -Iinclude -std=c++11 src/params.pb.cc src/library.cpp `pkg-config --cflags --libs protobuf` && \
    ar rcs libprotobufExample.a params.pb.o library.o

# For CPP only test uncomment next 2 rows
#RUN g++ -Iinclude -std=c++11 main.cpp libprotobufExample.a `pkg-config --cflags --libs protobuf` && ./a.out; exit 1

RUN cp libprotobufExample.a pkg/lib/. && cp include/library.h pkg/lib/.

#RUN mkdir pkg/exportParams
RUN protoc --go_out=pkg/exportParams/. params.proto
RUN go install github.com/im7mortal/cToGoProtobufExample/cmd/protobuf

RUN protoc --python_out=pkg/pyExe params.proto

RUN protobuf

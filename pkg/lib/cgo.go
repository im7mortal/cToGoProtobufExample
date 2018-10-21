package lib

// #cgo pkg-config: protobuf
// #cgo LDFLAGS: -L. -lprotobufExample
// #cgo LDFLAGS: -lstdc++
// #cgo CXXFLAGS: -std=c++11 -I.
import "C"

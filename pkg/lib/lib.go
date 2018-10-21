package lib

// #include <stdlib.h>
// #include "library.h"
import "C"

import (
	"unsafe"
	"context"
	"github.com/im7mortal/cToGoProtobufExample/pkg/exportParams"
)

// I use 1 mb what is a lot just for example
const mb = 1000000

// ctx?  just keep it!!!
func Get(ctx context.Context) (e exportParams.ExportParams, err error) {
	// Allocate array where C++ will put a descriptor
	response := make([]byte, mb, mb)
	// Pointer to response array in C format
	result := (*C.char)(unsafe.Pointer(&response[0]))
	// Send data to C++
	n, err := C.getData(result)
	// err is ERRNO
	if err != nil {
		println(err.Error())
		return
	}
	// actually you don't need even do it.
	response = response[:n]

	err = e.XXX_Unmarshal(response)

	if err != nil {
		println(err.Error())
	}
	return

}

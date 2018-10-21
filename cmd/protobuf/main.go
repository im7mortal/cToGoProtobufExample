package main

import (
	"github.com/im7mortal/cToGoProtobufExample/pkg/lib"
	"context"
	"fmt"
)

func main() {
	e, err := lib.Get(context.TODO())
	if err != nil {
		println(err.Error())
		return
	}
	fmt.Printf("%f\n", e.GetFloatVal())
	fmt.Printf("%d\n", e.GetIntVal())

	for _, i := range e.GetArrayOfData() {
		fmt.Printf("%f\n", i)
	}

	e.ArrayOfData = []float32{
		19.09, 0.3587,
	}

    println("SEND TO CPP")
	lib.Send(context.TODO(), e)

}
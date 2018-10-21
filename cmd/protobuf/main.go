package main

import (
	"github.com/im7mortal/cToGoProtobufExample/pkg/lib"
	"context"
	"fmt"
	"github.com/im7mortal/cToGoProtobufExample/pkg/pyExe"
	"log"
)

func main() {
	e, err := lib.Get(context.TODO())
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("GO\n")
	fmt.Printf("%f\n", e.GetFloatVal())
	fmt.Printf("%d\n", e.GetIntVal())

	for _, i := range e.GetArrayOfData() {
		fmt.Printf("%f\n", i)
	}

	e.ArrayOfData = []float32{
		19.09, 0.3587,
	}

	fmt.Printf("CPP\n")
	lib.Send(context.TODO(), e)

	fmt.Printf("PYTHON\n")
	e, err = pyExe.Process(context.TODO(), e)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%d\n", e.GetIntVal())

}
package pyExe

import (
	"context"
	"io/ioutil"
	"os/exec"
	"log"
	"github.com/im7mortal/cToGoProtobufExample/pkg/exportParams"
	"os"
)

func Process(ctx context.Context, req exportParams.ExportParams) (res exportParams.ExportParams, err error) {
	src, err := req.XXX_Marshal([]byte{}, true)
	if err != nil {
		log.Fatal(err)
		return
	}
	input := "/tmp/params.message"
	// Write the message to a tmp file
	err = ioutil.WriteFile(input, src, 0777)
	if err != nil {
		log.Fatal(err)
		return
	}

	output := "/tmp/params.out.message"

	cmd := exec.Command("python", "logic.py", input, output)
	cmd.Dir = "/go/src/github.com/im7mortal/cToGoProtobufExample/pkg/pyExe"
	cmd.Stderr = os.Stderr

	err = cmd.Run()
	if err != nil {
		log.Fatal(err)
	}

	buffer, err := ioutil.ReadFile(output)
	if err != nil {
		log.Fatal(err)
	}
	err = res.XXX_Unmarshal(buffer)
	if err != nil {
		log.Fatal(err)
	}
	return
}

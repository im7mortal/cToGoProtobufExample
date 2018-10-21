import sys

import params_pb2

src = sys.argv[1]
dst = sys.argv[2]


with open(src) as f:
    content = f.read()

e = params_pb2.ExportParams()
e.ParseFromString(content)

sys.stderr.write("HI from PYTHON \n")
sys.stderr.write(str(e.IntVal))
sys.stderr.write("\n")
e.IntVal = 987811

with open(dst, 'w') as f:
    f.write(e.SerializeToString())
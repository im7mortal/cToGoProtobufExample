#include "params.pb.h"

#include <iostream>
#include <vector>


struct Params {
    int IntVal;
    float FloatVal;
    std::size_t SomeSize;
    std::vector<float> ArrayOfData;
};

Params InternalGenerator() {
    Params params;
    params.IntVal = 1009;
    params.FloatVal = 89.7;
    params.ArrayOfData = std::vector<float>{908,7,0.89881};
    return params;
}

extern "C" {
unsigned long getData(char *data) {
    Params params = InternalGenerator();

    // Prepare export
    exportParams::ExportParams ex;
    ex.set_intval(params.IntVal);
    ex.set_floatval(params.FloatVal);
    for (auto i = 0; i < params.ArrayOfData.size(); i++){
        ex.add_arrayofdata(params.ArrayOfData[i]);
    }

    std::string bytes = ex.SerializeAsString();
    const char* array = bytes.data();

    for (auto i = 0; i < bytes.size(); i++){
        data[i] = array[i];
    }

    return bytes.size();
}
void sendData(char *data) {

    exportParams::ExportParams ex;
    std::string bytes(data);
    ex.ParseFromString(bytes);
    std::cerr << "IntVal " << ex.intval() << "\n";
    std::cerr << "FloatVal " << ex.floatval() << "\n";

    for (auto i = 0; i < ex.arrayofdata_size(); i++){
        std::cerr << "ArrayOfData " << ex.arrayofdata(i) << "\n";
    }
}
}


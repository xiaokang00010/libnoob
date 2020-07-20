#include "ElangInclude.h"

using namespace std;
using namespace dataobj;

int main(int argc, const char* argv[]){
    EConfig conf = EConfig("./test.econf");
    cout << conf.readString("read.text");
    conf.writeString("read.text","helloworld!");
    conf.commitChanges();
    conf = EConfig("./test.econf");
    cout << conf.readString("read.text");
}

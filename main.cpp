#include <iostream>
#include <list>
#include "things.h"

#ifndef   UNUSED_PARAM
#define   UNUSED_PARAM(v)   (void)(v)
#endif

using namespace std;
using namespace uml;

int main(int argc, char *argv[])
{
    UNUSED_PARAM(argc);
    UNUSED_PARAM(argv);

    uml::Class c;
    uml::Parameter p("inout", "p1", "t1", "d1");
    uml::Parameter p2("p2", "t2", "d2");
    uml::Parameter p3("p3", "t3");
    uml::Parameter p4("p4");
    cout << p.toString().toStdString() << endl << p2.toString().toStdString() << endl
         << p3.toString().toStdString() << endl << p4.toString().toStdString() << endl;

    uml::Operation o1("o1");
    cout << o1.toString().toStdString() << endl;

//    c.attributes.push_back();

    QString s("QString");
    cout << s.toStdString() << endl;

    uml::ObjectFlow of;

    cout << "Hello World!" << endl;
    return 0;
}

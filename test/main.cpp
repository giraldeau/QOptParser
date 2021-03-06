#include "QOptParser"

int main(int argc, char ** argv) {
    QOptParser parser(argc,argv);
    QTextStream stream(stdout,QIODevice::WriteOnly);

    QOption help('h',"help","ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff g","durrrr");
    QOption shortOnly('s',QString(),"Option with only short trigger");
    QOption longOnly(QChar(),"long","Option with only long trigger","baka");

    parser.addOption(&help,"");
    parser.addOption(&shortOnly,"Test");
    parser.addOption(&longOnly,"Test");

    parser.setBanner(QString("%1 [OPTIONS]\n").arg(argv[0]));

    bool result = parser.parse();
    if (result) {
        stream << "Leftovers:" << endl;
        foreach (QString lo, parser.getLeftovers()) {
            stream << QString("'%1'").arg(lo) << endl;
        }
    }

    return 0;
}

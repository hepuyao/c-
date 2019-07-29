#ifndef REGEXPINTERFACE_H
#define REGEXPINTERFACE_H

#include <QString>

#define RegExpInterface_iid "anobodykey.RegExpInterface/1.0"
//声明纯虚函数的一般形式是 virtual 函数类型 函数名 (参数表列) =0;
class RegExpInterface
{
public:
    virtual ~RegExpInterface(){}
    virtual QString regexp(const QString &message)=0;
};
Q_DECLARE_INTERFACE(RegExpInterface, RegExpInterface_iid)
#endif // REGEXPINTERFACE_H

#ifndef REGEXPPLUGIN_H
#define REGEXPPLUGIN_H

#include "plugin_global.h"
#include <QObject>
#include "regexpinterface.h"

class PLUGINSHARED_EXPORT RegExpPlugin :public QObject,RegExpInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "anobodykey.RegExpInterface/1.0" FILE "regexpplugin.json")
    Q_INTERFACES(RegExpInterface)
public:
    RegExpPlugin();
    QString regexp(const QString &message);
};

#endif // REGEXPPLUGIN_H


#ifndef GETSYSPROPERTYCMDXML_H
#define GETSYSPROPERTYCMDXML_H

#include <QSharedPointer>
#include "ICmdXMLGenerator.h"
#include "XMLFileAssistant.h"

class GetSysPropertyCmdXML : public ICmdXMLGenerator
{
public:
    GetSysPropertyCmdXML();

    XML_CMD_GENERATOR_VIRTUAL_FUNCS

    QString getCmdValue() const;

private:
    QSharedPointer<XMLTargetFileAssistant> m_target_file_assist;
};

#endif // GETSYSPROPERTYCMDXML_H

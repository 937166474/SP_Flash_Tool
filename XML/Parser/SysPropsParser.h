#ifndef SYSPROPSPARSER_H
#define SYSPROPSPARSER_H

#include "IXMLParser.h"

class SysPropsParser: public IXMLParser
{
public:
    SysPropsParser() {}
    virtual ~SysPropsParser() {}

    bool DASLAEnabled() const;

protected:
    virtual bool parseDocument(const QDomElement &root_node) override;

private:
    bool parseItemElement(const QDomElement &item_node);
    bool parseNodeValue(QString &tag_value, const QDomElement &root_node, const QString &tag_name);

private:
    QString m_da_sla_enabled;
};

#endif // SYSPROPSPARSER_H

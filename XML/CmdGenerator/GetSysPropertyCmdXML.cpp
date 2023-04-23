#include "GetSysPropertyCmdXML.h"

GetSysPropertyCmdXML::GetSysPropertyCmdXML():
    ICmdXMLGenerator(GET_SYS_PROPERTY_CMD_VER_VAL, GET_SYS_PROPERTY_CMD_NAME_VAL, DA_NODE_NAME),
    m_target_file_assist(new XMLTargetFileAssistant())
{

}

QString GetSysPropertyCmdXML::getCmdValue() const
{
    return m_target_file_assist->getCmdXMLValue();
}

/*
<?xml version="1.0" encoding="utf-8"?>
<da>
    <version>1.0</version>
    <command>CMD:GET-SYS-PROPERTY</command>
    <arg>
        <key>product_id</key>
        <target_file>MEM://0x2000000:0x20000</target_file>
    </arg>
</da>

The return string is like below:
    <?xml version="1.0" encoding="utf-8"?>
    <sys_prop version=”1.0”>
        <item key=”to-be-impl”>AAAAAAAA</item>
        <item key=”to-be-impl2>AAAAAAAA</item>
    </sys_prop>
*/
void GetSysPropertyCmdXML::fillArgNode(QDomElement * const arg_node)
{
    assert(nullptr != arg_node);

    m_target_file_assist->setFileType(FILE_TYPE::MEMORY_FILE);
    this->createXMLSubNode(arg_node, KEY_NODE_NAME, DA_SLA_VAL_NAME);
    this->createXMLSubNode(arg_node, TARGET_FILE_NODE_NAME, m_target_file_assist->getFileDesc());
}

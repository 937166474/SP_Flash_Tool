#include <QSettings>

#include "EnvGenUtils.h"

QSharedPointer<EnvGenUtils> EnvGenUtils::m_instance = QSharedPointer<EnvGenUtils>();

EnvGenUtils::EnvGenUtils()
{
}

EnvGenUtils::~EnvGenUtils()
{
}

QSharedPointer<EnvGenUtils> EnvGenUtils::getInstance()
{
    // ONLY used in main thread, so NO NEED to care multi-thread condition.
    if (!m_instance)
        m_instance = QSharedPointer<EnvGenUtils>(new EnvGenUtils());
    return m_instance;
}

void EnvGenUtils::genEnvBinary(QString dev_type, QString dev_chip, QString dev_version, QString dev_id, QString bootmode, bool automation = 1, bool resvm = 1)
{
    int total_size, offset;

    if (dev_type == "mt6833") {
        total_size = 0x240000;
        offset = 0x200000;
    } else {
        total_size = 0x2000;
        offset = 0;
    }

    
}

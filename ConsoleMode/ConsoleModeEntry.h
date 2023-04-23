#ifndef CONSOLEMODEENTRY_H
#define CONSOLEMODEENTRY_H

#include <QCoreApplication>
#include <QSharedPointer>
#include "../Utility/LogFilesClean.h"

class NetworkThread;

namespace ConsoleMode
{

class CommandLineArguments;

class ConsoleModeEntry
{
public:
    ConsoleModeEntry();
    virtual ~ConsoleModeEntry();

    int run(const QStringList &arguments);
    bool network_online() const;

private:
    void openAndCleanLogs(std::shared_ptr<CommandLineArguments> &cmd_args) const;

private:
    ConsoleModeEntry(const ConsoleModeEntry &) = delete;
    ConsoleModeEntry & operator=(const ConsoleModeEntry &) = delete;

    ConsoleModeEntry(const ConsoleModeEntry &&) = delete;
    ConsoleModeEntry & operator=(const ConsoleModeEntry &&) = delete;

private:
    QSharedPointer<NetworkThread> m_network_thread;
};

}

#endif // CONSOLEMODEENTRY_H

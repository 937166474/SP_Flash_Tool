/*
 * Log.h
 *
 *  Created on: Aug 27, 2011
 *      Author: MTK81019
 */

#ifndef LOG_H_
#define LOG_H_

#include "Logger.h"

#define LOG (LogFunc(Logger::Debug, __FUNCTION__, __FILE__, __LINE__))
#define LOGV (LogFunc(Logger::Verbose, __FUNCTION__, __FILE__, __LINE__))
#define LOGD (LogFunc(Logger::Debug, __FUNCTION__, __FILE__, __LINE__))
#define LOGI (LogFunc(Logger::Info, __FUNCTION__, __FILE__, __LINE__))
#define LOGW (LogFunc(Logger::Warn, __FUNCTION__, __FILE__, __LINE__))
#define LOGE (LogFunc(Logger::Error, __FUNCTION__, __FILE__, __LINE__))

class LogOperationMgr
{
public:
    static void LogSwitch(bool enabled_log);
    static void ResetLogPath(const std::string &new_log_path, bool need_restart_log = true);

private:
    static void DebugLogsOn(void);
    static void DebugLogsOff(void);
};

#endif /* LOG_H_ */

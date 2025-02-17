// Copyright (c) 2023 FlyByWire Simulations
// SPDX-License-Identifier: GPL-3.0

#ifndef FLYBYWIRE_LOGGING_H
#define FLYBYWIRE_LOGGING_H

#include <iostream>

/**
 * Simple logging facility for the FlyByWire Simulations C++ WASM framework.
 * No performance when turned off and only the minimum overhead when turned on to a specific level.
 *
 * Use in the following way:
 *
 * LOG_INFO("PANEL_SERVICE_PRE_INSTALL");
 * LOG_INFO("PANEL_SERVICE_PRE_INSTALL: " + panelService->getPanelServiceName());
 *
 * This will be improved and extended in the future.
 * E.g. it could be extended to log to a file.
 */

#define ZERO_LVL 0
#define CRITICAL_LVL 1
#define ERROR_LVL 2
#define WARN_LVL 3
#define INFO_LVL 4
#define DEBUG_LVL 5
#define VERBOSE_LVL 6
#define TRACE_LVL 7

#if LOG_LEVEL > ZERO_LVL
#define LOG_CRITICAL(msg) logger->critical(msg)
#define LOG_CRITICAL_BLOCK(block) block
#else
#define LOG_CRITICAL(msg) void(0)
#define LOG_CRITICAL_BLOCK(block) void(0);
#endif

#if LOG_LEVEL > CRITICAL_LVL
#define LOG_ERROR(msg) logger->error(msg)
#define LOG_ERROR_BLOCK(block) block
#else
#define LOG_ERROR(msg) void(0)
#define LOG_ERROR_BLOCK(block) void(0);
#endif

#if LOG_LEVEL > ERROR_LVL
#define LOG_WARN(msg) logger->warn(msg)
#define LOG_WARN_BLOCK(block) block
#else
#define LOG_WARN(msg) void(0)
#define LOG_WARN_BLOCK(block) void(0);
#endif

#if LOG_LEVEL > WARN_LVL
#define LOG_INFO(msg) logger->info(msg)
#define LOG_INFO_BLOCK(block) block
#else
#define LOG_INFO(msg) void(0)
#define LOG_INFO_BLOCK(block) void(0);
#endif

#if LOG_LEVEL > INFO_LVL
#define LOG_DEBUG(msg) logger->debug(msg)
#define LOG_DEBUG_BLOCK(block) block
#else
#define LOG_DEBUG(msg) void(0)
#define LOG_DEBUG_BLOCK(block) void(0);
#endif

#if LOG_LEVEL > DEBUG_LVL
#define LOG_VERBOSE(msg) logger->verbose(msg)
#define LOG_VERBOSE_BLOCK(block) block
#else
#define LOG_VERBOSE(msg) void(0)
#define LOG_VERBOSE_BLOCK(block) void(0);
#endif

#if LOG_LEVEL > VERBOSE_LVL
#define LOG_TRACE(msg) logger->trace(msg)
#define LOG_TRACE_BLOCK(block) block
#else
#define LOG_TRACE(msg) void(0)
#define LOG_TRACE_BLOCK(block) void(0);
#endif

/**
 * @brief The Logger class is a very simple logging facility.
 *
 * Singleton class for Logger
 * Very simple implementation for now.
 */
class Logger {
 public:
  Logger() = default;
  /** get the singleton instance of Logger */
  static Logger* instance() {
    static Logger instance;
    return &instance;
  }

 public:
  // disallow copies
  Logger(Logger const&) = delete;              // copy
  Logger& operator=(const Logger&) = delete;   // copy assignment
  Logger(Logger const&&) = delete;             // move
  Logger& operator=(const Logger&&) = delete;  // move assignment

  void critical(const std::string& msg) { std::cerr << "critical: " + msg; }
  void error(const std::string& msg) { std::cerr << "error: " + msg; }
  void warn(const std::string& msg) { std::cerr << "warn: " + msg; }
  void info(const std::string& msg) { std::cout << "info: " << msg << std::endl; }
  void debug(const std::string& msg) { std::cout << "debug: " << msg << std::endl; }
  void verbose(const std::string& msg) { std::cout << "verbose: " << msg << std::endl; }
  void trace(const std::string& msg) { std::cout << "trace: " << msg << std::endl; }
};

inline Logger* logger = Logger::instance();

#endif  // FLYBYWIRE_LOGGING_H

# CLog

CLog (which stands of cool log) is a simple logging library instended to be simple and flexible for all applications. Take a look at this example:
```cpp
CLog::Logger myLogger("Example Logger");
myLogger.AddSink<CLog::Sinks::ConsoleSink>();
myLogger.AddSink<CLog::Sinks::FileSink>("latest.log");
myLogger.Info("Hello World!");
myLogger.Debug("Hello World!");
myLogger.Warn("Hello World!");
myLogger.Error("Hello World!");
```

Which would print this in console:

<img width="357" height="91" alt="image" src="https://github.com/user-attachments/assets/1f3635e0-3134-44c1-a22e-2eb3a977322c" />

As well as a log file containing:
```txt
[INFO] Hello World!
[DEBUG] Hello World!
[WARNING] Hello World!
[ERROR] Hello World!
```

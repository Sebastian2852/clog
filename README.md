# CLog

CLog (which stands of cool log) is a simple header only log library instended to be simple and flexible for all applications. Take a look at this example:
```cpp
CLog::Logger myLogger("{COLOR_START}[{PREFIX}] {MESSAGE}{COLOR_END}");
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

---

# Usage

This is a header-only library meaning that to use it all you need is the `include` folder and add it to your project (along with adding an include directory that points to it).

CLog is fully extendable so you can add your own sinks that behave in whatever way you like. You can have a look at the built-in sinks [here](https://github.com/Sebastian2852/clog/blob/main/include/CLog/Sink.hpp).

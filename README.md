# CLog

CLog (which stands for cool log) is a logging library designed to have a really simple API while being super flexible. You can look under the `example` directory to get a basic understanding of how CLog works. In short CLog allows you to create logger classes and add sinks to them. Those sinks implement how the logger will actually "print" out its logs. This means that if you dont like anything about how CLog works out the box you can create your own sink which works how *you* would like it to.

Here is a basic code example for creating a logger and logging a message:
```cpp
#include "CLog.hpp"

int main()
{
  // Create a logger; there is a default format provided which works with the built-in sinks
  CLog::Logger myLogger("My Logger");

  // Add the console sink which is a built-in sink which prints out COLORED logs to the console window
  myLogger.AddSink<CLog::Sinks::ConsoleSink>();

  // Add the file sink which is a built-int sink which prints out plain-text logs into the passed file
  myLogger.AddSink<CLog::Sinks::FileSink>("latest.log");

  // Now the logger is ready to use
  myLogger.Info("Hello World!");
  myLogger.Debug("Hello World!");
  myLogger.Warn("Hello World!");
  myLogger.Error("Hello World!");
}
```

CLog also supports the FMT library meaning that you can also write logs like this:
```cpp
  CLog::Logger myLogger("My Logger");
  myLogger.Trace("We {1} {0}!", "fmt", "support");
```

I wont go into detail on how to write your own `Sink`s but they are really simple they boil down to a single `Print` function which you implement in your sink, you should use the built-in sinks as a guide. 

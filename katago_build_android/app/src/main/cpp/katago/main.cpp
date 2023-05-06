#include "main.h"

#include "core/os.h"
#include "core/mainargs.h"

#ifdef NO_GIT_REVISION
#define GIT_REVISION "<omitted>"
#else
#include "program/gitinfotemplate.h"
#endif

#include <sstream>

//------------------------
#include "core/using.h"
//------------------------

static void printHelp(const vector<string>& args) {
  cout << endl;
  if(args.size() >= 1)
    cout << "Usage: " << args[0] << " SUBCOMMAND ";
  else
    cout << "Usage: " << "./katago" << " SUBCOMMAND ";
  cout << endl;

  cout << R"%%(
---Common subcommands------------------
// ********引擎启动前的信息******


gtp : Runs GTP engine that can be plugged into any standard Go GUI for play/analysis.
            运行GTP引擎，可以插入任何标准的围棋图形用户界面进行游戏/分析。
benchmark : Test speed with different numbers of search threads.
            用不同数量的搜索线程测试速度
genconfig : User-friendly interface to generate a config with rules and automatic performance tuning.
            用户友好的界面，生成带有规则和自动性能调整的配置。
contribute : Connect to online distributed KataGo training and run perpetually contributing selfplay games.
            连接到在线分布式KataGo培训并运行永久贡献的自我游戏。
match : Run self-play match games based on a config, more efficient than gtp due to batching.
            根据配置运行自我对弈的游戏，由于分批进行，比gtp更有效率。
version : Print version and exit.
            打印版本并退出。
analysis : Runs an engine designed to analyze entire games in parallel.
            运行一个旨在并行分析整个游戏的引擎。
tuner : (OpenCL only) Run tuning to find and optimize parameters that work on your GPU.
            (仅限OpenCL）运行调整，找到并优化在你的GPU上工作的参数。
---Selfplay training subcommands---------

selfplay : Play selfplay games and generate training data.
           自我对弈并产生训练数据。
gatekeeper : Poll directory for new nets and match them against the latest net so far.
             调查目录，
---Testing/debugging subcommands 测试/调试子命令-------------
evalsgf : Utility/debug tool, analyze a single position of a game from an SGF file.
            从SGF文件中分析游戏的单一位置

runtests : Test important board algorithms and datastructures
            测试重要的棋盘算法和数据结构
runnnlayertests : Test a few subcomponents of the current neural net backend
                    测试当前神经网络后台的几个子组件
runnnontinyboardtest : Run neural net on a tiny board and dump result to stdout
                        在一个小棋盘上运行神经网络，并将结果转储到stdout
runnnsymmetriestest : Run neural net on a hardcoded rectangle board and dump symmetries result
                        在一个硬编码的矩形板上运行神经网，并转储对称性结果
runownershiptests : Run neural net search on some hardcoded positions and print avg ownership
                    在一些硬编码的位置上运行神经网络搜索，并打印平均所有权（胜率）。

runoutputtests : Run a bunch of things and dump details to stdout
runsearchtests : Run a bunch of things using a neural net and dump details to stdout
runsearchtestsv3 : Run a bunch more things using a neural net and dump details to stdout
runsearchtestsv8 : Run a bunch more things using a neural net and dump details to stdout
runselfplayinittests : Run some tests involving selfplay training init using a neural net and dump details to stdout
runsekitrainwritetests : Run some tests involving seki train output

)%%" << endl;
}

static int handleSubcommand(const string& subcommand, const vector<string>& args) {
  vector<string> subArgs(args.begin()+1,args.end());
  if(subcommand == "analysis")
    return MainCmds::analysis(subArgs);
  if(subcommand == "benchmark")
    return MainCmds::benchmark(subArgs);
  if(subcommand == "contribute")
    return MainCmds::contribute(subArgs);
  if(subcommand == "evalsgf")
    return MainCmds::evalsgf(subArgs);
  else if(subcommand == "gatekeeper")
    return MainCmds::gatekeeper(subArgs);
  else if(subcommand == "genconfig")
    return MainCmds::genconfig(subArgs,args[0]);
  else if(subcommand == "gtp")
    return MainCmds::gtp(subArgs);
  else if(subcommand == "tuner")
    return MainCmds::tuner(subArgs);
  else if(subcommand == "match")
    return MainCmds::match(subArgs);
  else if(subcommand == "matchauto")
    return MainCmds::matchauto(subArgs);
  else if(subcommand == "selfplay")
    return MainCmds::selfplay(subArgs);
  else if(subcommand == "runtests")
    return MainCmds::runtests(subArgs);
  else if(subcommand == "runnnlayertests")
    return MainCmds::runnnlayertests(subArgs);
  else if(subcommand == "runnnontinyboardtest")
    return MainCmds::runnnontinyboardtest(subArgs);
  else if(subcommand == "runnnsymmetriestest")
    return MainCmds::runnnsymmetriestest(subArgs);
  else if(subcommand == "runownershiptests")
    return MainCmds::runownershiptests(subArgs);
  else if(subcommand == "runoutputtests")
    return MainCmds::runoutputtests(subArgs);
  else if(subcommand == "runsearchtests")
    return MainCmds::runsearchtests(subArgs);
  else if(subcommand == "runsearchtestsv3")
    return MainCmds::runsearchtestsv3(subArgs);
  else if(subcommand == "runsearchtestsv8")
    return MainCmds::runsearchtestsv8(subArgs);
  else if(subcommand == "runselfplayinittests")
    return MainCmds::runselfplayinittests(subArgs);
  else if(subcommand == "runselfplayinitstattests")
    return MainCmds::runselfplayinitstattests(subArgs);
  else if(subcommand == "runsekitrainwritetests")
    return MainCmds::runsekitrainwritetests(subArgs);
  else if(subcommand == "runnnonmanyposestest")
    return MainCmds::runnnonmanyposestest(subArgs);
  else if(subcommand == "runnnbatchingtest")
    return MainCmds::runnnbatchingtest(subArgs);
  else if(subcommand == "runtinynntests")
    return MainCmds::runtinynntests(subArgs);
  else if(subcommand == "runnnevalcanarytests")
    return MainCmds::runnnevalcanarytests(subArgs);
  else if(subcommand == "samplesgfs")
    return MainCmds::samplesgfs(subArgs);
  else if(subcommand == "dataminesgfs")
    return MainCmds::dataminesgfs(subArgs);
  else if(subcommand == "genbook")
//    return MainCmds::genbook(subArgs);
 // else if(subcommand == "trystartposes")
    return MainCmds::trystartposes(subArgs);
  else if(subcommand == "viewstartposes")
    return MainCmds::viewstartposes(subArgs);
  else if(subcommand == "demoplay")
    return MainCmds::demoplay(subArgs);
  else if(subcommand == "sampleinitializations")
    return MainCmds::sampleinitializations(subArgs);
  else if(subcommand == "runbeginsearchspeedtest")
    return MainCmds::runbeginsearchspeedtest(subArgs);
  else if(subcommand == "runsleeptest")
    return MainCmds::runsleeptest(subArgs);
  else if(subcommand == "printclockinfo")
    return MainCmds::printclockinfo(subArgs);
  else if(subcommand == "sandbox")
    return MainCmds::sandbox();
  else if(subcommand == "version") {
    cout << Version::getKataGoVersionFullInfo() << std::flush;
    return 0;
  }
  else {
    cout << "Unknown subcommand: " << subcommand << endl;
    printHelp(args);
    return 1;
  }
  return 0;
}

//const char* const*  常量指针常量    比如.\katago.exe gtp -config default_gtp.cfg -model b30.bin.gz
// 启动后，参数argv里的内容就是gtp -config default_gtp.cfg -model b30.bin.gz 不能说再输入gtp工作模式以外的指令，比如本来是在gtp模式工作的，不能说切换到sandbox模式，这样
// 只能是在第一次启动才能选择的
// const char* const*  常量指针常量  这样做的目的是为了防止指向argv的指针发生变化，而且防止指针所在内存里面的内容被篡改
// 指针设为常量不能变，里面的内容也为常量，不允许改变
int main(int argc, const char* const* argv) {
  vector<string> args = MainArgs::getCommandLineArgsUTF8(argc,argv);

  if(args.size() < 2) {
    printHelp(args);
    return 0;
  }
  string cmdArg = string(args[1]);
  if(cmdArg == "-h" || cmdArg == "--h" || cmdArg == "-help" || cmdArg == "--help" || cmdArg == "help") {
    printHelp(args);
    return 0;
  }

#if defined(OS_IS_WINDOWS)
  //On windows, uncaught exceptions reaching toplevel don't normally get printed out,
  //so explicitly catch everything and print
  int result;
  try {
    result = handleSubcommand(cmdArg, args);
  }
  catch(std::exception& e) {
    cerr << "Uncaught exception: " << e.what() << endl;
    return 1;
  }
  catch(...) {
    cerr << "Uncaught exception that is not a std::exception... exiting due to unknown error" << endl;
    return 1;
  }
  return result;
#else
  return handleSubcommand(cmdArg, args);
#endif
}


string Version::getKataGoVersion() {
  return string("1.10.0");
}

string Version::getKataGoVersionForHelp() {
  return string("KataGo v1.10.0");
}

string Version::getKataGoVersionFullInfo() {
  ostringstream out;
  out << Version::getKataGoVersionForHelp() << endl;
  out << "Git revision: " << Version::getGitRevision() << endl;
  out << "Compile Time: " << __DATE__ << " " << __TIME__ << endl;
#if defined(USE_CUDA_BACKEND)
  out << "Using CUDA backend" << endl;
#if defined(CUDA_TARGET_VERSION)
#define STRINGIFY(x) #x
#define STRINGIFY2(x) STRINGIFY(x)
  out << "Compiled with CUDA version " << STRINGIFY2(CUDA_TARGET_VERSION) << endl;
#endif
#elif defined(USE_TENSORRT_BACKEND)
  out << "Using TensorRT backend" << endl;
#elif defined(USE_OPENCL_BACKEND)
  out << "Using OpenCL backend" << endl;
#elif defined(USE_EIGEN_BACKEND)
  out << "Using Eigen(CPU) backend" << endl;
#else
  out << "Using dummy backend" << endl;
#endif

#if defined(USE_AVX2)
  out << "Compiled with AVX2 and FMA instructions" << endl;
#endif
#if defined(COMPILE_MAX_BOARD_LEN)
  out << "Compiled to allow boards of size up to " << COMPILE_MAX_BOARD_LEN << endl;
#endif
#if defined(BUILD_DISTRIBUTED)
  out << "Compiled to support contributing to online distributed selfplay" << endl;
#endif

  return out.str();
}

string Version::getGitRevision() {
  return string(GIT_REVISION);
}

string Version::getGitRevisionWithBackend() {
  string s = string(GIT_REVISION);

#if defined(USE_CUDA_BACKEND)
  s += "-cuda";
#elif defined(USE_TENSORRT_BACKEND)
  s += "-trt";
#elif defined(USE_OPENCL_BACKEND)
  s += "-opencl";
#elif defined(USE_EIGEN_BACKEND)
  s += "-eigen";
#else
  s += "-dummy";
#endif
  return s;
}

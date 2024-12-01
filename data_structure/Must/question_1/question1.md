### 1.题目名称

**系统进程统计**

### 2.代码行数

496行

### 3.算法思想

#### 1.扫取进程

​		获取程序快照，并创建结构体，随后遍历进程，对结构体相关信息进行赋值，并将结构体插入vector。

#### 2.链表操作

​		通过遍历进程，将进程按是否正在运行存入相应集合，如果不存在于集合则插入对应集合，并插入相应的链表。如果存在于某一集合，则执行刷新操作。如果该进程状态改变则移除先前状态集合以及链表，执行插入操作，插入对应状态集合以及链表，否则更新进程状态即可。（遍历的同时对每个进程的持续时间用map进行存储，便于后续读取以及使用)

​		遍历完毕后，对链表按内存进行排序即可。

#### 3.输出操作

​		先输出进程名以及内存容量，随后将开始时间转成北京时间输出，最后输出持续时间。(如果进程结束,则需要输出结束时间)	

### 4.主要/核心函数分析

#### updateList

```c++
void updateList(LinerList **Hder , CircleList **Hd, LinerList **Eder , CircleList **Ed, ProcessInfo tmp, bool flag, bool same){}
```

通过flag变量去判断执行插入还是刷新。

通过same变量去判断进程状态对应数据结构。

在刷新操作中，如果进程状态未变，则直接刷新对应进程状态即可，否则调整该进程相对应的数据结构，并调用函数自身进行插入操作。

#### getProcessInfo

```c++
// 获取当前系统的进程信息
vector<ProcessInfo> getProcessInfo() {}
```

获取程序快照，并创建结构体，随后遍历进程，对结构体相关信息进行赋值，并将结构体插入vector，最后返回该vector即可。

####	sortListByMemory

```c++
void sortListByMemory(LinerList*& head) {}
void sortListByMemory(CircleList*& head) {}
```

冒泡排序，对系统进程按内存进行排序。

### 5.测试数据(规模,测试次数)

规模:电脑正在运行的进程。

测试次数：约1s扫一次 扫10次。

### 6.运行结果

中途执行关闭QQ操作，可以发现QQ相关进程出现在已关闭进程中。

```txt
F:\data_structure\Must\question_1\cmake-build-debug\question_1.exe
Status: 1
Process Name: clion64.exe
Memory Usage: 2618720256
Creation Time: 2023-12-31 14:11:04
Last Time: 31seconds

Process Name: clangd.exe
Memory Usage: 622751744
Creation Time: 2023-12-31 14:11:08
Last Time: 27seconds

Process Name: explorer.exe
Memory Usage: 451637248
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: Typora.exe
Memory Usage: 291459072
Creation Time: 2023-12-31 14:09:58
Last Time: 97seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4858seconds

Process Name: TIM.exe
Memory Usage: 240365568
Creation Time: 2023-12-31 14:01:13
Last Time: 622seconds

Process Name: dwm.exe
Memory Usage: 239013888
Creation Time: 2023-12-31 12:50:26
Last Time: 4869seconds

Process Name: HipsDaemon.exe
Memory Usage: 224681984
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198782976
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146653184
Creation Time: 2023-12-31 12:50:49
Last Time: 4846seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4865seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4865seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: java.exe
Memory Usage: 110264320
Creation Time: 2023-12-31 14:11:34
Last Time: 1seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4577seconds

Process Name: OneDrive.exe
Memory Usage: 95891456
Creation Time: 2023-12-31 12:50:41
Last Time: 4854seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4736seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4856seconds

Process Name: cef_frame_render.exe
Memory Usage: 83001344
Creation Time: 2023-12-31 12:50:54
Last Time: 4841seconds

Process Name: TextInputHost.exe
Memory Usage: 79962112
Creation Time: 2023-12-31 12:50:40
Last Time: 4855seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4865seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4865seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4865seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4864seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4850seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4862seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4851seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61939712
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 621seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: IGCCTray.exe
Memory Usage: 48881664
Creation Time: 2023-12-31 12:50:48
Last Time: 4847seconds

Process Name: ChsIME.exe
Memory Usage: 48312320
Creation Time: 2023-12-31 12:50:33
Last Time: 4862seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: lsass.exe
Memory Usage: 44691456
Creation Time: 2023-12-31 12:50:26
Last Time: 4869seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4611seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4863seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4863seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4862seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4863seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1433seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4623seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3017seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4847seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1901seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: IGCC.exe
Memory Usage: 24698880
Creation Time: 2023-12-31 12:50:52
Last Time: 4843seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3967seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4564seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4865seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 429seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 2seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4378seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1231seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4857seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3888seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4864seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4562seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 622seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4864seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 1seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4869seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4576seconds

Process Name: PopBlock.exe
Memory Usage: 11169792
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4849seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4848seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3012seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4855seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4747seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 71seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4864seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4846seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4850seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4864seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4866seconds

Process Name: question_1.exe
Memory Usage: 8187904
Creation Time: 2023-12-31 14:11:34
Last Time: 1seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 1seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4863seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4866seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4844seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4854seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4866seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4747seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4844seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4845seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4844seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4852seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4846seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 29seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: TXPlatform.exe
Memory Usage: 3391488
Creation Time: 2023-12-31 14:01:14
Last Time: 621seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4869seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4866seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4845seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4868seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1368064
Creation Time: 2023-12-31 12:55:36
Last Time: 4559seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4862seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1265664
Creation Time: 2023-12-31 12:50:33
Last Time: 4862seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4860seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4867seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4862seconds

Status: 0
Status: 1
Process Name: clion64.exe
Memory Usage: 2631348224
Creation Time: 2023-12-31 14:11:04
Last Time: 32seconds

Process Name: clangd.exe
Memory Usage: 622751744
Creation Time: 2023-12-31 14:11:08
Last Time: 28seconds

Process Name: explorer.exe
Memory Usage: 451538944
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: Typora.exe
Memory Usage: 291459072
Creation Time: 2023-12-31 14:09:58
Last Time: 98seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4859seconds

Process Name: TIM.exe
Memory Usage: 240365568
Creation Time: 2023-12-31 14:01:13
Last Time: 623seconds

Process Name: dwm.exe
Memory Usage: 239009792
Creation Time: 2023-12-31 12:50:26
Last Time: 4870seconds

Process Name: HipsDaemon.exe
Memory Usage: 224681984
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198782976
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146653184
Creation Time: 2023-12-31 12:50:49
Last Time: 4847seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4866seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4866seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: java.exe
Memory Usage: 112963584
Creation Time: 2023-12-31 14:11:34
Last Time: 2seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4578seconds

Process Name: OneDrive.exe
Memory Usage: 95870976
Creation Time: 2023-12-31 12:50:41
Last Time: 4855seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4737seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4857seconds

Process Name: cef_frame_render.exe
Memory Usage: 83001344
Creation Time: 2023-12-31 12:50:54
Last Time: 4842seconds

Process Name: TextInputHost.exe
Memory Usage: 79962112
Creation Time: 2023-12-31 12:50:40
Last Time: 4856seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4866seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4866seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4866seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4865seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4851seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4863seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4852seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61939712
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 622seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: IGCCTray.exe
Memory Usage: 48881664
Creation Time: 2023-12-31 12:50:48
Last Time: 4848seconds

Process Name: ChsIME.exe
Memory Usage: 48312320
Creation Time: 2023-12-31 12:50:33
Last Time: 4863seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: lsass.exe
Memory Usage: 44691456
Creation Time: 2023-12-31 12:50:26
Last Time: 4870seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4612seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4864seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4864seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4863seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4864seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1434seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4624seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3018seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4848seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1902seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: IGCC.exe
Memory Usage: 24698880
Creation Time: 2023-12-31 12:50:52
Last Time: 4844seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3968seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4565seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4866seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 430seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 3seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4379seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1232seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4858seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3889seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4865seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4563seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 623seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4865seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 2seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4870seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4577seconds

Process Name: PopBlock.exe
Memory Usage: 11169792
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4850seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4849seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3013seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4856seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4748seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 72seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4865seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4847seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4851seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4865seconds

Process Name: question_1.exe
Memory Usage: 8474624
Creation Time: 2023-12-31 14:11:34
Last Time: 2seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4867seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 2seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4864seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4867seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4845seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4855seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4867seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4748seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4845seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4846seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4845seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4853seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4847seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 30seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: TXPlatform.exe
Memory Usage: 3391488
Creation Time: 2023-12-31 14:01:14
Last Time: 622seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4870seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4867seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4846seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4869seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1368064
Creation Time: 2023-12-31 12:55:36
Last Time: 4560seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4863seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1261568
Creation Time: 2023-12-31 12:50:33
Last Time: 4863seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4861seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4868seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4863seconds

Status: 0
Status: 1
Process Name: clion64.exe
Memory Usage: 2674987008
Creation Time: 2023-12-31 14:11:04
Last Time: 34seconds

Process Name: clangd.exe
Memory Usage: 622751744
Creation Time: 2023-12-31 14:11:08
Last Time: 30seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: Typora.exe
Memory Usage: 291459072
Creation Time: 2023-12-31 14:09:58
Last Time: 100seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4861seconds

Process Name: dwm.exe
Memory Usage: 239398912
Creation Time: 2023-12-31 12:50:26
Last Time: 4871seconds

Process Name: TIM.exe
Memory Usage: 233390080
Creation Time: 2023-12-31 14:01:13
Last Time: 625seconds

Process Name: HipsDaemon.exe
Memory Usage: 224681984
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198782976
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146653184
Creation Time: 2023-12-31 12:50:49
Last Time: 4849seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4867seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4867seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: java.exe
Memory Usage: 113344512
Creation Time: 2023-12-31 14:11:34
Last Time: 4seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4580seconds

Process Name: OneDrive.exe
Memory Usage: 95870976
Creation Time: 2023-12-31 12:50:41
Last Time: 4857seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4739seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4859seconds

Process Name: cef_frame_render.exe
Memory Usage: 83001344
Creation Time: 2023-12-31 12:50:54
Last Time: 4844seconds

Process Name: TextInputHost.exe
Memory Usage: 79970304
Creation Time: 2023-12-31 12:50:40
Last Time: 4858seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4867seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4867seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4867seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4866seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4853seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4865seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4854seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61939712
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: IGCCTray.exe
Memory Usage: 48881664
Creation Time: 2023-12-31 12:50:48
Last Time: 4850seconds

Process Name: ChsIME.exe
Memory Usage: 48312320
Creation Time: 2023-12-31 12:50:33
Last Time: 4865seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: lsass.exe
Memory Usage: 44691456
Creation Time: 2023-12-31 12:50:26
Last Time: 4871seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4614seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4866seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4866seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4865seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4866seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1436seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4626seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3020seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4850seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1904seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: IGCC.exe
Memory Usage: 24698880
Creation Time: 2023-12-31 12:50:52
Last Time: 4846seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3970seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4567seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4867seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 432seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 5seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4381seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1234seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4860seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3891seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4867seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4565seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 625seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4866seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 4seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4871seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4579seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4852seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4851seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3015seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4858seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4750seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 74seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4866seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4849seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4853seconds

Process Name: question_1.exe
Memory Usage: 8495104
Creation Time: 2023-12-31 14:11:34
Last Time: 4seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4866seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4868seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 4seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4866seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4868seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4847seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4857seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4868seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4750seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4847seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4848seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4847seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4855seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4849seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 32seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: TXPlatform.exe
Memory Usage: 3391488
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4871seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4868seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4848seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4870seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1368064
Creation Time: 2023-12-31 12:55:36
Last Time: 4562seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4865seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1257472
Creation Time: 2023-12-31 12:50:33
Last Time: 4865seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4863seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4869seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4865seconds

Status: 0
Status: 1
Process Name: clion64.exe
Memory Usage: 2687000576
Creation Time: 2023-12-31 14:11:04
Last Time: 35seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 31seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: Typora.exe
Memory Usage: 291459072
Creation Time: 2023-12-31 14:09:58
Last Time: 101seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4862seconds

Process Name: dwm.exe
Memory Usage: 234082304
Creation Time: 2023-12-31 12:50:26
Last Time: 4873seconds

Process Name: TIM.exe
Memory Usage: 225673216
Creation Time: 2023-12-31 14:01:13
Last Time: 626seconds

Process Name: HipsDaemon.exe
Memory Usage: 224686080
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198889472
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146681856
Creation Time: 2023-12-31 12:50:49
Last Time: 4850seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4869seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4869seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: java.exe
Memory Usage: 113651712
Creation Time: 2023-12-31 14:11:34
Last Time: 5seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4581seconds

Process Name: OneDrive.exe
Memory Usage: 95870976
Creation Time: 2023-12-31 12:50:41
Last Time: 4858seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4740seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4860seconds

Process Name: cef_frame_render.exe
Memory Usage: 83013632
Creation Time: 2023-12-31 12:50:54
Last Time: 4845seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4859seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4869seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4869seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4869seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4868seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4854seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4866seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4855seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61939712
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: IGCCTray.exe
Memory Usage: 48881664
Creation Time: 2023-12-31 12:50:48
Last Time: 4851seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4866seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: lsass.exe
Memory Usage: 44691456
Creation Time: 2023-12-31 12:50:26
Last Time: 4873seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4615seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4867seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4867seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4866seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4867seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1437seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4627seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3021seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4851seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1905seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: IGCC.exe
Memory Usage: 24698880
Creation Time: 2023-12-31 12:50:52
Last Time: 4847seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3971seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4568seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4869seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 433seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 6seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4382seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1235seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4861seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3892seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4868seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4566seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 626seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4868seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 5seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4873seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4580seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4853seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4852seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3016seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4859seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4751seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 75seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4868seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4850seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4854seconds

Process Name: question_1.exe
Memory Usage: 8499200
Creation Time: 2023-12-31 14:11:34
Last Time: 5seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4868seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4870seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 5seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4867seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4870seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4848seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4858seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4870seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4751seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4848seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4849seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4848seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4856seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: TXPlatform.exe
Memory Usage: 4419584
Creation Time: 2023-12-31 14:01:14
Last Time: 625seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4850seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 33seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4873seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4870seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4849seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4872seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1363968
Creation Time: 2023-12-31 12:55:36
Last Time: 4563seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4866seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1253376
Creation Time: 2023-12-31 12:50:33
Last Time: 4866seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4864seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4871seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4866seconds

Status: 0
Status: 1
Process Name: clion64.exe
Memory Usage: 2687053824
Creation Time: 2023-12-31 14:11:04
Last Time: 36seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 32seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: Typora.exe
Memory Usage: 291459072
Creation Time: 2023-12-31 14:09:58
Last Time: 102seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4863seconds

Process Name: dwm.exe
Memory Usage: 234082304
Creation Time: 2023-12-31 12:50:26
Last Time: 4874seconds

Process Name: TIM.exe
Memory Usage: 229810176
Creation Time: 2023-12-31 14:01:13
Last Time: 627seconds

Process Name: HipsDaemon.exe
Memory Usage: 224686080
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198889472
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146681856
Creation Time: 2023-12-31 12:50:49
Last Time: 4851seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4870seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4870seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: java.exe
Memory Usage: 111931392
Creation Time: 2023-12-31 14:11:34
Last Time: 6seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4582seconds

Process Name: OneDrive.exe
Memory Usage: 95870976
Creation Time: 2023-12-31 12:50:41
Last Time: 4859seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4741seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4861seconds

Process Name: cef_frame_render.exe
Memory Usage: 83013632
Creation Time: 2023-12-31 12:50:54
Last Time: 4846seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4860seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4870seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4870seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4870seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4869seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4855seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4867seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4856seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61939712
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: IGCCTray.exe
Memory Usage: 48881664
Creation Time: 2023-12-31 12:50:48
Last Time: 4852seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4867seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: lsass.exe
Memory Usage: 44691456
Creation Time: 2023-12-31 12:50:26
Last Time: 4874seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4616seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4868seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4868seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4867seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4868seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1438seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4628seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3022seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4852seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1906seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: IGCC.exe
Memory Usage: 24698880
Creation Time: 2023-12-31 12:50:52
Last Time: 4848seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3972seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4569seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4870seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 434seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 7seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4383seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1236seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4862seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3893seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4869seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4567seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 627seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4869seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 6seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4874seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4581seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4854seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4853seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3017seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4860seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4752seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 76seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4869seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4851seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4855seconds

Process Name: question_1.exe
Memory Usage: 8515584
Creation Time: 2023-12-31 14:11:34
Last Time: 6seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4869seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4871seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 6seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4868seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4871seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4849seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4859seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4871seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4752seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4849seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4850seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4849seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4857seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: TXPlatform.exe
Memory Usage: 4419584
Creation Time: 2023-12-31 14:01:14
Last Time: 626seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4851seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 34seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4874seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4871seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4850seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4873seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1359872
Creation Time: 2023-12-31 12:55:36
Last Time: 4564seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4867seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1249280
Creation Time: 2023-12-31 12:50:33
Last Time: 4867seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4865seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4872seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4867seconds

Status: 0
Status: 1
Process Name: clion64.exe
Memory Usage: 2673987584
Creation Time: 2023-12-31 14:11:04
Last Time: 37seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 33seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: Typora.exe
Memory Usage: 291459072
Creation Time: 2023-12-31 14:09:58
Last Time: 103seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4864seconds

Process Name: dwm.exe
Memory Usage: 234082304
Creation Time: 2023-12-31 12:50:26
Last Time: 4875seconds

Process Name: HipsDaemon.exe
Memory Usage: 224686080
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: TIM.exe
Memory Usage: 223604736
Creation Time: 2023-12-31 14:01:13
Last Time: 628seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198889472
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146681856
Creation Time: 2023-12-31 12:50:49
Last Time: 4852seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4871seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4871seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: java.exe
Memory Usage: 113500160
Creation Time: 2023-12-31 14:11:34
Last Time: 7seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4583seconds

Process Name: OneDrive.exe
Memory Usage: 95870976
Creation Time: 2023-12-31 12:50:41
Last Time: 4860seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4742seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4862seconds

Process Name: cef_frame_render.exe
Memory Usage: 83267584
Creation Time: 2023-12-31 12:50:54
Last Time: 4847seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4861seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4871seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4871seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4871seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4870seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4856seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4868seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4857seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61939712
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: IGCCTray.exe
Memory Usage: 48881664
Creation Time: 2023-12-31 12:50:48
Last Time: 4853seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4868seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: lsass.exe
Memory Usage: 44691456
Creation Time: 2023-12-31 12:50:26
Last Time: 4875seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4617seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4869seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4869seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4868seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4869seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1439seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4629seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3023seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4853seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1907seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: IGCC.exe
Memory Usage: 24698880
Creation Time: 2023-12-31 12:50:52
Last Time: 4849seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3973seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4570seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4871seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 435seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 8seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4384seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1237seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4863seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3894seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4870seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4568seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 628seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4870seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 7seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4875seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4582seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4855seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4854seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3018seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4861seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4753seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 77seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4870seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4852seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4856seconds

Process Name: question_1.exe
Memory Usage: 8536064
Creation Time: 2023-12-31 14:11:34
Last Time: 7seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4870seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4872seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 7seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4869seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4872seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4850seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4860seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4872seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4753seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4850seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4851seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4850seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4858seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: TXPlatform.exe
Memory Usage: 4419584
Creation Time: 2023-12-31 14:01:14
Last Time: 627seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4852seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 35seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4875seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4872seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4851seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4874seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1355776
Creation Time: 2023-12-31 12:55:36
Last Time: 4565seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4868seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1245184
Creation Time: 2023-12-31 12:50:33
Last Time: 4868seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4866seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4873seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4868seconds

Status: 0
Status: 1
Process Name: clion64.exe
Memory Usage: 2690494464
Creation Time: 2023-12-31 14:11:04
Last Time: 38seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 34seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: Typora.exe
Memory Usage: 291467264
Creation Time: 2023-12-31 14:09:58
Last Time: 104seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4865seconds

Process Name: dwm.exe
Memory Usage: 234082304
Creation Time: 2023-12-31 12:50:26
Last Time: 4876seconds

Process Name: HipsDaemon.exe
Memory Usage: 224686080
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: TIM.exe
Memory Usage: 221786112
Creation Time: 2023-12-31 14:01:13
Last Time: 629seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198889472
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146681856
Creation Time: 2023-12-31 12:50:49
Last Time: 4853seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4872seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4872seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: java.exe
Memory Usage: 113860608
Creation Time: 2023-12-31 14:11:34
Last Time: 8seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4584seconds

Process Name: OneDrive.exe
Memory Usage: 95870976
Creation Time: 2023-12-31 12:50:41
Last Time: 4861seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4743seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4863seconds

Process Name: cef_frame_render.exe
Memory Usage: 83267584
Creation Time: 2023-12-31 12:50:54
Last Time: 4848seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4862seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4872seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4872seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4872seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4871seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4857seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4869seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4858seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61939712
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: IGCCTray.exe
Memory Usage: 48881664
Creation Time: 2023-12-31 12:50:48
Last Time: 4854seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4869seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: lsass.exe
Memory Usage: 44691456
Creation Time: 2023-12-31 12:50:26
Last Time: 4876seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4618seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4870seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4870seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4869seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4870seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1440seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4630seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3024seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4854seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1908seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: IGCC.exe
Memory Usage: 24698880
Creation Time: 2023-12-31 12:50:52
Last Time: 4850seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3974seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4571seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4872seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 436seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 9seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4385seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1238seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4864seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3895seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4871seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4569seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 629seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4871seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 8seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4876seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4583seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4856seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4855seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3019seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4862seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4754seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 78seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4871seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4853seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4857seconds

Process Name: question_1.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 14:11:34
Last Time: 8seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4871seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4873seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 8seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4870seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4873seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4851seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4861seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4873seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4754seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4851seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4852seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4851seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4859seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: TXPlatform.exe
Memory Usage: 4419584
Creation Time: 2023-12-31 14:01:14
Last Time: 628seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4853seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 36seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4876seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4873seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4852seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4875seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1351680
Creation Time: 2023-12-31 12:55:36
Last Time: 4566seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4869seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1241088
Creation Time: 2023-12-31 12:50:33
Last Time: 4869seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4867seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4874seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4869seconds

Status: 0
Status: 1
Process Name: clion64.exe
Memory Usage: 2690789376
Creation Time: 2023-12-31 14:11:04
Last Time: 39seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 35seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: Typora.exe
Memory Usage: 291450880
Creation Time: 2023-12-31 14:09:58
Last Time: 105seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4866seconds

Process Name: dwm.exe
Memory Usage: 234082304
Creation Time: 2023-12-31 12:50:26
Last Time: 4877seconds

Process Name: HipsDaemon.exe
Memory Usage: 224686080
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: TIM.exe
Memory Usage: 214474752
Creation Time: 2023-12-31 14:01:13
Last Time: 630seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198995968
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146681856
Creation Time: 2023-12-31 12:50:49
Last Time: 4854seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4873seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4873seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: java.exe
Memory Usage: 114233344
Creation Time: 2023-12-31 14:11:34
Last Time: 9seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4585seconds

Process Name: OneDrive.exe
Memory Usage: 95870976
Creation Time: 2023-12-31 12:50:41
Last Time: 4862seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4744seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4864seconds

Process Name: cef_frame_render.exe
Memory Usage: 83267584
Creation Time: 2023-12-31 12:50:54
Last Time: 4849seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4863seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4873seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4873seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4873seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4872seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4858seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63508480
Creation Time: 2023-12-31 12:50:33
Last Time: 4870seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4859seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61943808
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: IGCCTray.exe
Memory Usage: 48865280
Creation Time: 2023-12-31 12:50:48
Last Time: 4855seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4870seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: lsass.exe
Memory Usage: 44695552
Creation Time: 2023-12-31 12:50:26
Last Time: 4877seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4619seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4871seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4871seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4870seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4871seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1441seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4631seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3025seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4855seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1909seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: IGCC.exe
Memory Usage: 24702976
Creation Time: 2023-12-31 12:50:52
Last Time: 4851seconds

Process Name: SDXHelper.exe
Memory Usage: 22757376
Creation Time: 2023-12-31 13:05:28
Last Time: 3975seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4572seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4873seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 437seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 10seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4386seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1239seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4865seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3896seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4872seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4570seconds

Process Name: smartscreen.exe
Memory Usage: 12472320
Creation Time: 2023-12-31 14:01:13
Last Time: 630seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4872seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 9seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4877seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4584seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4857seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4856seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3020seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4863seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4755seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 79seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4872seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4854seconds

Process Name: question_1.exe
Memory Usage: 8552448
Creation Time: 2023-12-31 14:11:34
Last Time: 9seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4858seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4872seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4874seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 9seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4871seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4874seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4852seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4862seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4874seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4755seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4852seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4853seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4852seconds

Process Name: TXPlatform.exe
Memory Usage: 4640768
Creation Time: 2023-12-31 14:01:14
Last Time: 629seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4860seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4854seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 37seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4877seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4874seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4853seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4876seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1347584
Creation Time: 2023-12-31 12:55:36
Last Time: 4567seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4870seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1236992
Creation Time: 2023-12-31 12:50:33
Last Time: 4870seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4868seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4875seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4870seconds

Status: 0
1Status: 1
Process Name: clion64.exe
Memory Usage: 2691293184
Creation Time: 2023-12-31 14:11:04
Last Time: 40seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 36seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: Typora.exe
Memory Usage: 293011456
Creation Time: 2023-12-31 14:09:58
Last Time: 106seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4867seconds

Process Name: dwm.exe
Memory Usage: 233754624
Creation Time: 2023-12-31 12:50:26
Last Time: 4878seconds

Process Name: HipsDaemon.exe
Memory Usage: 224751616
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198995968
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146710528
Creation Time: 2023-12-31 12:50:49
Last Time: 4855seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4874seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4874seconds

Process Name: java.exe
Memory Usage: 114671616
Creation Time: 2023-12-31 14:11:34
Last Time: 10seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4586seconds

Process Name: OneDrive.exe
Memory Usage: 96169984
Creation Time: 2023-12-31 12:50:41
Last Time: 4863seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4745seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4865seconds

Process Name: cef_frame_render.exe
Memory Usage: 83300352
Creation Time: 2023-12-31 12:50:54
Last Time: 4850seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4864seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4874seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4874seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4874seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4873seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4859seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63549440
Creation Time: 2023-12-31 12:50:33
Last Time: 4871seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4860seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61943808
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: IGCCTray.exe
Memory Usage: 48865280
Creation Time: 2023-12-31 12:50:48
Last Time: 4856seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4871seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: lsass.exe
Memory Usage: 44695552
Creation Time: 2023-12-31 12:50:26
Last Time: 4878seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4620seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4872seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4872seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4871seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4872seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1442seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32477184
Creation Time: 2023-12-31 12:54:32
Last Time: 4632seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3026seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4856seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1910seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: IGCC.exe
Memory Usage: 24702976
Creation Time: 2023-12-31 12:50:52
Last Time: 4852seconds

Process Name: SDXHelper.exe
Memory Usage: 22749184
Creation Time: 2023-12-31 13:05:28
Last Time: 3976seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4573seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4874seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 438seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 11seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4387seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1240seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4866seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3897seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4873seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4571seconds

Process Name: smartscreen.exe
Memory Usage: 12460032
Creation Time: 2023-12-31 14:01:13
Last Time: 631seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4873seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 10seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4878seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4585seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4858seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4857seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3021seconds

Process Name: HipsTray.exe
Memory Usage: 9629696
Creation Time: 2023-12-31 12:50:40
Last Time: 4864seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4756seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 80seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4873seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4855seconds

Process Name: question_1.exe
Memory Usage: 8552448
Creation Time: 2023-12-31 14:11:34
Last Time: 10seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4859seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4873seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4875seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 10seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4872seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4875seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4853seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4863seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4875seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4756seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4853seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4854seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4853seconds

Process Name: TXPlatform.exe
Memory Usage: 4640768
Creation Time: 2023-12-31 14:01:14
Last Time: 629seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4861seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4855seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 38seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4878seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4875seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4854seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4877seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1343488
Creation Time: 2023-12-31 12:55:36
Last Time: 4568seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4871seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1232896
Creation Time: 2023-12-31 12:50:33
Last Time: 4871seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4869seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4876seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4871seconds

Status: 0
Process Name: TIM.exe
Memory Usage: 20480
Creation Time: 2023-12-31 14:01:13
Last Time: 630seconds
End Time: 2023-12-31 14:11:43

Status: 1
Process Name: clion64.exe
Memory Usage: 2691477504
Creation Time: 2023-12-31 14:11:04
Last Time: 41seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 37seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: Typora.exe
Memory Usage: 293011456
Creation Time: 2023-12-31 14:09:58
Last Time: 107seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4868seconds

Process Name: dwm.exe
Memory Usage: 233086976
Creation Time: 2023-12-31 12:50:26
Last Time: 4879seconds

Process Name: HipsDaemon.exe
Memory Usage: 224751616
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198995968
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146710528
Creation Time: 2023-12-31 12:50:49
Last Time: 4856seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4875seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4875seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: java.exe
Memory Usage: 113668096
Creation Time: 2023-12-31 14:11:34
Last Time: 11seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4587seconds

Process Name: OneDrive.exe
Memory Usage: 96169984
Creation Time: 2023-12-31 12:50:41
Last Time: 4864seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4746seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4866seconds

Process Name: cef_frame_render.exe
Memory Usage: 83300352
Creation Time: 2023-12-31 12:50:54
Last Time: 4851seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4865seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4875seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4875seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4875seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4874seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4860seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63549440
Creation Time: 2023-12-31 12:50:33
Last Time: 4872seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4861seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61943808
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: IGCCTray.exe
Memory Usage: 48865280
Creation Time: 2023-12-31 12:50:48
Last Time: 4857seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4872seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: lsass.exe
Memory Usage: 44675072
Creation Time: 2023-12-31 12:50:26
Last Time: 4879seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4621seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4873seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4873seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4872seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4873seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1443seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32505856
Creation Time: 2023-12-31 12:54:32
Last Time: 4633seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3027seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4857seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1911seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: IGCC.exe
Memory Usage: 24702976
Creation Time: 2023-12-31 12:50:52
Last Time: 4853seconds

Process Name: SDXHelper.exe
Memory Usage: 22749184
Creation Time: 2023-12-31 13:05:28
Last Time: 3977seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4574seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4875seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 439seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 12seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4388seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1241seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4867seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3898seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4874seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4572seconds

Process Name: smartscreen.exe
Memory Usage: 12460032
Creation Time: 2023-12-31 14:01:13
Last Time: 632seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4874seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 11seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4879seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4586seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4859seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4858seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3022seconds

Process Name: HipsTray.exe
Memory Usage: 9351168
Creation Time: 2023-12-31 12:50:40
Last Time: 4865seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4757seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 81seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4874seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4856seconds

Process Name: question_1.exe
Memory Usage: 8568832
Creation Time: 2023-12-31 14:11:34
Last Time: 11seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4860seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4874seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4876seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 11seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4873seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4876seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4854seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4864seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4876seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4757seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4854seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4855seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4854seconds

Process Name: TXPlatform.exe
Memory Usage: 4640768
Creation Time: 2023-12-31 14:01:14
Last Time: 629seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4862seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4856seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 39seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4879seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4876seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4855seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4878seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1339392
Creation Time: 2023-12-31 12:55:36
Last Time: 4569seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4872seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1228800
Creation Time: 2023-12-31 12:50:33
Last Time: 4872seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4870seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4877seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4872seconds

Status: 0
Process Name: TIM.exe
Memory Usage: 20480
Creation Time: 2023-12-31 14:01:13
Last Time: 630seconds
End Time: 2023-12-31 14:11:43

Status: 1
Process Name: clion64.exe
Memory Usage: 2687434752
Creation Time: 2023-12-31 14:11:04
Last Time: 42seconds

Process Name: clangd.exe
Memory Usage: 622735360
Creation Time: 2023-12-31 14:11:08
Last Time: 38seconds

Process Name: explorer.exe
Memory Usage: 451575808
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: Typora.exe
Memory Usage: 293011456
Creation Time: 2023-12-31 14:09:58
Last Time: 108seconds

Process Name: PhoneExperienceHost.exe
Memory Usage: 265252864
Creation Time: 2023-12-31 12:50:37
Last Time: 4869seconds

Process Name: dwm.exe
Memory Usage: 233086976
Creation Time: 2023-12-31 12:50:26
Last Time: 4880seconds

Process Name: HipsDaemon.exe
Memory Usage: 224751616
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: ArmouryCrate.Service.exe
Memory Usage: 198995968
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: NVIDIA Share.exe
Memory Usage: 146710528
Creation Time: 2023-12-31 12:50:49
Last Time: 4857seconds

Process Name: kwallpaper.exe
Memory Usage: 140038144
Creation Time: 2023-12-31 12:50:30
Last Time: 4876seconds

Process Name: SearchHost.exe
Memory Usage: 136450048
Creation Time: 2023-12-31 12:50:30
Last Time: 4876seconds

Process Name: AcPowerNotification.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: java.exe
Memory Usage: 114339840
Creation Time: 2023-12-31 14:11:34
Last Time: 12seconds

Process Name: SystemSettings.exe
Memory Usage: 100208640
Creation Time: 2023-12-31 12:55:18
Last Time: 4588seconds

Process Name: OneDrive.exe
Memory Usage: 96169984
Creation Time: 2023-12-31 12:50:41
Last Time: 4865seconds

Process Name: AsusSoftwareManagerAgent.exe
Memory Usage: 95289344
Creation Time: 2023-12-31 12:52:39
Last Time: 4747seconds

Process Name: nvcontainer.exe
Memory Usage: 83783680
Creation Time: 2023-12-31 12:50:39
Last Time: 4867seconds

Process Name: cef_frame_render.exe
Memory Usage: 83300352
Creation Time: 2023-12-31 12:50:54
Last Time: 4852seconds

Process Name: TextInputHost.exe
Memory Usage: 79974400
Creation Time: 2023-12-31 12:50:40
Last Time: 4866seconds

Process Name: kdesk64.exe
Memory Usage: 79822848
Creation Time: 2023-12-31 12:50:30
Last Time: 4876seconds

Process Name: StartMenuExperienceHost.exe
Memory Usage: 70660096
Creation Time: 2023-12-31 12:50:30
Last Time: 4876seconds

Process Name: Widgets.exe
Memory Usage: 69742592
Creation Time: 2023-12-31 12:50:30
Last Time: 4876seconds

Process Name: Windows.Media.BackgroundPlayback.exe
Memory Usage: 67051520
Creation Time: 2023-12-31 12:50:31
Last Time: 4875seconds

Process Name: AppMarket.exe
Memory Usage: 63909888
Creation Time: 2023-12-31 12:50:45
Last Time: 4861seconds

Process Name: NVIDIA Web Helper.exe
Memory Usage: 63549440
Creation Time: 2023-12-31 12:50:33
Last Time: 4873seconds

Process Name: QQMusic.exe
Memory Usage: 63496192
Creation Time: 2023-12-31 12:50:44
Last Time: 4862seconds

Process Name: NVDisplay.Container.exe
Memory Usage: 61943808
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: ArmouryCrate.UserSessionHelper.exe
Memory Usage: 60018688
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: OfficeClickToRun.exe
Memory Usage: 54702080
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: QQExternal.exe
Memory Usage: 50020352
Creation Time: 2023-12-31 14:01:14
Last Time: 624seconds

Process Name: sihost.exe
Memory Usage: 49909760
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: IGCCTray.exe
Memory Usage: 48865280
Creation Time: 2023-12-31 12:50:48
Last Time: 4858seconds

Process Name: ChsIME.exe
Memory Usage: 48226304
Creation Time: 2023-12-31 12:50:33
Last Time: 4873seconds

Process Name: OneApp.IGCC.WinService.exe
Memory Usage: 45137920
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: lsass.exe
Memory Usage: 44675072
Creation Time: 2023-12-31 12:50:26
Last Time: 4880seconds

Process Name: backgroundTaskHost.exe
Memory Usage: 41734144
Creation Time: 2023-12-31 12:54:44
Last Time: 4622seconds

Process Name: ctfmon.exe
Memory Usage: 40771584
Creation Time: 2023-12-31 12:50:32
Last Time: 4874seconds

Process Name: LockApp.exe
Memory Usage: 40280064
Creation Time: 2023-12-31 12:50:32
Last Time: 4874seconds

Process Name: asus_framework.exe
Memory Usage: 37036032
Creation Time: 2023-12-31 12:50:33
Last Time: 4873seconds

Process Name: SearchIndexer.exe
Memory Usage: 36888576
Creation Time: 2023-12-31 12:50:32
Last Time: 4874seconds

Process Name: msedge.exe
Memory Usage: 33198080
Creation Time: 2023-12-31 13:47:42
Last Time: 1444seconds

Process Name: ApplicationFrameHost.exe
Memory Usage: 32505856
Creation Time: 2023-12-31 12:54:32
Last Time: 4634seconds

Process Name: AutoConnectHelper.exe
Memory Usage: 32333824
Creation Time: 2023-12-31 13:21:18
Last Time: 3028seconds

Process Name: LightingService.exe
Memory Usage: 30294016
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: CCleaner64.exe
Memory Usage: 28901376
Creation Time: 2023-12-31 12:50:48
Last Time: 4858seconds

Process Name: audiodg.exe
Memory Usage: 27680768
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: ROGLiveService.exe
Memory Usage: 26669056
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: RuntimeBroker.exe
Memory Usage: 26324992
Creation Time: 2023-12-31 13:39:54
Last Time: 1912seconds

Process Name: nisvcloc.exe
Memory Usage: 25858048
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: IGCC.exe
Memory Usage: 24702976
Creation Time: 2023-12-31 12:50:52
Last Time: 4854seconds

Process Name: SDXHelper.exe
Memory Usage: 22745088
Creation Time: 2023-12-31 13:05:28
Last Time: 3978seconds

Process Name: ShellExperienceHost.exe
Memory Usage: 22675456
Creation Time: 2023-12-31 12:55:31
Last Time: 4575seconds

Process Name: kwallpaperex.exe
Memory Usage: 20824064
Creation Time: 2023-12-31 12:50:30
Last Time: 4876seconds

Process Name: FileCoAuth.exe
Memory Usage: 20508672
Creation Time: 2023-12-31 14:04:26
Last Time: 440seconds

Process Name: launcher.exe
Memory Usage: 19505152
Creation Time: 2023-12-31 14:11:33
Last Time: 13seconds

Process Name: FileSyncHelper.exe
Memory Usage: 18264064
Creation Time: 2023-12-31 12:58:37
Last Time: 4389seconds

Process Name: QQProtect.exe
Memory Usage: 18214912
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: FLMgrTray.exe
Memory Usage: 17944576
Creation Time: 2023-12-31 13:51:04
Last Time: 1242seconds

Process Name: AsusSoftwareManager.exe
Memory Usage: 17518592
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: AsusAppService.exe
Memory Usage: 17313792
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: WidgetService.exe
Memory Usage: 16060416
Creation Time: 2023-12-31 12:50:38
Last Time: 4868seconds

Process Name: spoolsv.exe
Memory Usage: 15986688
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: vmware-authd.exe
Memory Usage: 15167488
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: HaoZipService.exe
Memory Usage: 14217216
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: wpscloudsvr.exe
Memory Usage: 13967360
Creation Time: 2023-12-31 13:06:47
Last Time: 3899seconds

Process Name: ArmouryCrateControlInterface.exe
Memory Usage: 13697024
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: keyemain.exe
Memory Usage: 13443072
Creation Time: 2023-12-31 12:50:31
Last Time: 4875seconds

Process Name: HaoZipWorker.exe
Memory Usage: 12697600
Creation Time: 2023-12-31 12:55:33
Last Time: 4573seconds

Process Name: smartscreen.exe
Memory Usage: 12460032
Creation Time: 2023-12-31 14:01:13
Last Time: 633seconds

Process Name: dllhost.exe
Memory Usage: 12279808
Creation Time: 2023-12-31 12:50:31
Last Time: 4875seconds

Process Name: conhost.exe
Memory Usage: 12124160
Creation Time: 2023-12-31 14:11:34
Last Time: 12seconds

Process Name: FLServer.exe
Memory Usage: 11919360
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: kdeskcore.exe
Memory Usage: 11702272
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: WUDFHost.exe
Memory Usage: 11657216
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: AsusLinkNear.exe
Memory Usage: 11579392
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: winlogon.exe
Memory Usage: 11497472
Creation Time: 2023-12-31 12:50:26
Last Time: 4880seconds

Process Name: AsusOptimizationStartupTask.exe
Memory Usage: 11272192
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: UserOOBEBroker.exe
Memory Usage: 11206656
Creation Time: 2023-12-31 12:55:19
Last Time: 4587seconds

Process Name: PopBlock.exe
Memory Usage: 11202560
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: DAX3API.exe
Memory Usage: 11010048
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: CMediaAudioControlPanel.exe
Memory Usage: 10366976
Creation Time: 2023-12-31 12:50:46
Last Time: 4860seconds

Process Name: nvsphelper64.exe
Memory Usage: 9981952
Creation Time: 2023-12-31 12:50:47
Last Time: 4859seconds

Process Name: WmiPrvSE.exe
Memory Usage: 9756672
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: ACCIMonitor.exe
Memory Usage: 9682944
Creation Time: 2023-12-31 13:21:23
Last Time: 3023seconds

Process Name: HipsTray.exe
Memory Usage: 9351168
Creation Time: 2023-12-31 12:50:40
Last Time: 4866seconds

Process Name: AsusSystemAnalysis.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 12:52:28
Last Time: 4758seconds

Process Name: svchost.exe
Memory Usage: 8978432
Creation Time: 2023-12-31 14:10:24
Last Time: 82seconds

Process Name: ArmouryCrate.exe
Memory Usage: 8966144
Creation Time: 2023-12-31 12:50:31
Last Time: 4875seconds

Process Name: vmware-usbarbitrator64.exe
Memory Usage: 8769536
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: wlanext.exe
Memory Usage: 8597504
Creation Time: 2023-12-31 12:50:49
Last Time: 4857seconds

Process Name: question_1.exe
Memory Usage: 8589312
Creation Time: 2023-12-31 14:11:34
Last Time: 12seconds

Process Name: YunDetectService.exe
Memory Usage: 8540160
Creation Time: 2023-12-31 12:50:45
Last Time: 4861seconds

Process Name: kdeskassist.exe
Memory Usage: 8491008
Creation Time: 2023-12-31 12:50:31
Last Time: 4875seconds

Process Name: ipf_helper.exe
Memory Usage: 8212480
Creation Time: 2023-12-31 12:50:29
Last Time: 4877seconds

Process Name: elevator.exe
Memory Usage: 8134656
Creation Time: 2023-12-31 14:11:34
Last Time: 12seconds

Process Name: ArmouryCrate.DenoiseAI.exe
Memory Usage: 7933952
Creation Time: 2023-12-31 12:50:32
Last Time: 4874seconds

Process Name: AggregatorHost.exe
Memory Usage: 7892992
Creation Time: 2023-12-31 12:50:29
Last Time: 4877seconds

Process Name: Intel_PIE_Service.exe
Memory Usage: 7520256
Creation Time: 2023-12-31 12:50:51
Last Time: 4855seconds

Process Name: AsusLinkRemote.exe
Memory Usage: 7155712
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: ArmourySocketServer.exe
Memory Usage: 7147520
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: ipf_uf.exe
Memory Usage: 7114752
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: RstMwService.exe
Memory Usage: 6950912
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: AsusSystemDiagnosis.exe
Memory Usage: 6877184
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: vgtray.exe
Memory Usage: 6631424
Creation Time: 2023-12-31 12:50:41
Last Time: 4865seconds

Process Name: QMEmulatorService.exe
Memory Usage: 6610944
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: AsusOptimization.exe
Memory Usage: 6569984
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: WMIRegistrationService.exe
Memory Usage: 6459392
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: ApplicationWebServer.exe
Memory Usage: 6209536
Creation Time: 2023-12-31 12:50:29
Last Time: 4877seconds

Process Name: unsecapp.exe
Memory Usage: 6197248
Creation Time: 2023-12-31 12:52:28
Last Time: 4758seconds

Process Name: AsusSwitch.exe
Memory Usage: 6135808
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: GameSDK.exe
Memory Usage: 5648384
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: taskhostw.exe
Memory Usage: 5619712
Creation Time: 2023-12-31 12:50:51
Last Time: 4855seconds

Process Name: nimdnsResponder.exe
Memory Usage: 5586944
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: vmware-tray.exe
Memory Usage: 5341184
Creation Time: 2023-12-31 12:50:50
Last Time: 4856seconds

Process Name: ipfsvc.exe
Memory Usage: 5246976
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: jhi_service.exe
Memory Usage: 5021696
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: FNPLicensingService.exe
Memory Usage: 4898816
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: AsusCertService.exe
Memory Usage: 4800512
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: syzs_dl_svr.exe
Memory Usage: 4718592
Creation Time: 2023-12-31 12:50:51
Last Time: 4855seconds

Process Name: TXPlatform.exe
Memory Usage: 4640768
Creation Time: 2023-12-31 14:01:14
Last Time: 629seconds

Process Name: AsusOSD.exe
Memory Usage: 4575232
Creation Time: 2023-12-31 12:50:43
Last Time: 4863seconds

Process Name: rundll32.exe
Memory Usage: 4509696
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: lkcitdl.exe
Memory Usage: 4427776
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: SystemWebServer.exe
Memory Usage: 4378624
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: nierserver.exe
Memory Usage: 4030464
Creation Time: 2023-12-31 12:50:49
Last Time: 4857seconds

Process Name: C-MediaAudioService.exe
Memory Usage: 3960832
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: IntelCpHDCPSvc.exe
Memory Usage: 3776512
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: nidmsrv.exe
Memory Usage: 3727360
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: fsnotifier.exe
Memory Usage: 3608576
Creation Time: 2023-12-31 14:11:06
Last Time: 40seconds

Process Name: lktsrv.exe
Memory Usage: 3596288
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: lkads.exe
Memory Usage: 3461120
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: vmnat.exe
Memory Usage: 3137536
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: fontdrvhost.exe
Memory Usage: 3096576
Creation Time: 2023-12-31 12:50:26
Last Time: 4880seconds

Process Name: NIWebServiceContainer.exe
Memory Usage: 2797568
Creation Time: 2023-12-31 12:50:29
Last Time: 4877seconds

Process Name: jusched.exe
Memory Usage: 2760704
Creation Time: 2023-12-31 12:50:50
Last Time: 4856seconds

Process Name: niauth_daemon.exe
Memory Usage: 2670592
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: vmnetdhcp.exe
Memory Usage: 2433024
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: usysdiag.exe
Memory Usage: 1392640
Creation Time: 2023-12-31 12:50:27
Last Time: 4879seconds

Process Name: LocationNotificationWindows.exe
Memory Usage: 1335296
Creation Time: 2023-12-31 12:55:36
Last Time: 4570seconds

Process Name: ArmouryHtmlDebugServer.exe
Memory Usage: 1282048
Creation Time: 2023-12-31 12:50:33
Last Time: 4873seconds

Process Name: GoogleCrashHandler.exe
Memory Usage: 1224704
Creation Time: 2023-12-31 12:50:33
Last Time: 4873seconds

Process Name: ArmourySwAgent.exe
Memory Usage: 1208320
Creation Time: 2023-12-31 12:50:35
Last Time: 4871seconds

Process Name: ASUSSmartDisplayControl.exe
Memory Usage: 1138688
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: AsHotplugCtrl.exe
Memory Usage: 1011712
Creation Time: 2023-12-31 12:50:28
Last Time: 4878seconds

Process Name: GoogleCrashHandler64.exe
Memory Usage: 548864
Creation Time: 2023-12-31 12:50:33
Last Time: 4873seconds

Status: 0
Process Name: TIM.exe
Memory Usage: 20480
Creation Time: 2023-12-31 14:01:13
Last Time: 630seconds
End Time: 2023-12-31 14:11:43


进程已结束,退出代码0

```



### 7.时间复杂度分析

对链表进行排序操作使用了冒泡排序，因此复杂度为O(n^2^)。

其余操作为O(n)或者O(1)。

因此最终复杂度为O(n^2^)。

### 8.结果截屏图片

![](F:\data_structure\Must\question_1\output.png)

### 9.心得体会

通过该题，我了解了系统进程该如何读取以及系统进程的一些信息和属性。在对进程进行处理的过程中，我更加熟悉链表的操作以及对构建出错时的处理更加得心应手。


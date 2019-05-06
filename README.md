#第 1 步：获取最新版本的 Xcode

要想使用PDChatSDK for iOS 开发项目，您需要 8.0 版或更高版本的 Xcode。

#第 2 步：获取 CocoaPods

PDChatSDK 以 CocoaPods pod 形式提供。 CocoaPods 是一种用于 Swift 和 Objective-C Cocoa 项目的开源依赖项管理器。

如果您尚未安装 CocoaPods 工具，请在 OS X 上从终端运行以下命令进行安装。 如需了解详情，请参阅 CocoaPods 入门指南。

$ sudo gem install cocoapods

#第 3 步：使用 CocoaPods 安装 SDK

为 PDChatSDK 创建一个 Podfile，并使用它来安装 SDK。
1、创建Podfile文件
在您当前工程文件（.xcodeproj）所在文件夹下创建一个名为 Podfile 的文件。如果您尚未创建 Xcode 项目，请立即创建一个并将其保存到您的本地计算机。 （如果您第一次接触 iOS 开发，请创建一个Single View Application。）
$ touch Podfile
2、编辑 Podfile 文件
Podfile文件内容如下：
platform :ios, '8.0' #手机的系统 target 'YourProjectTarget' do pod 'PDChatSDKFramework' end
3、运行 pod install 命令安装SDK
$pod install --repo-update
1.1.0版本的pod，运行pod install 不会自动更新repo，如果下载的不是最新版，可使用pod install —repo-update 更新 或 先运行 pod repo update.
4、更新 SDK
如果您安装的SDK不是最新版，请执行下面的代码进行更新。
pod repo update
5、重启 Xcode
关闭Xcode，然后打开（双击）您项目的 .xcworkspace 文件以启动 Xcode。 从此刻开始，您必须使用 .xcworkspace 文件打开项目。

#第 4 步：获取秘钥Key

请前往 http://cs-bv2-test.ipeidou.com/#/ 控制台申请 iOS Key。

#第 5 步：开始接入

1.配置Info.plist 文件

iOS9为了增强数据访问安全，将所有的http请求都改为了https，为了能够在iOS9中正常使用SDK，请在"Info.plist"中进行如下配置，否则影响SDK的使用。
<key>NSAppTransportSecurity</key>
<dict>
<key>NSAllowsArbitraryLoads</key>
<true></true>
</dict>

加入相应的权限授予
<key>NSCameraUsageDescription</key>
<string>我们需要使用您的相机进行拍照发送图片</string>
<key>NSLocationAlwaysUsageDescription</key>
<string>我们需要通过您的地理位置,发送位置信息给对方并且始终访问</string>
<key>NSLocationUsageDescription</key>
<string>我们需要通过您的地理位置,发送位置信息给对方</string>
<key>NSLocationWhenInUseUsageDescription</key>
<string>我们需要通过您的地理位置,发送位置信息给对方</string>
<key>NSMicrophoneUsageDescription</key>
<string>我们需要使用您的麦克风发送语音消息</string>
<key>NSPhotoLibraryAddUsageDescription</key>
<string>我们需要访问您的相册保存图片</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>我们需要访问您的相册发送图片消息</string>

2.配置秘钥Key至AppDelegate.m文件
将上面步骤获取的秘钥Key，配置到代码中，以保证功能的正常运行。代码如下：
#import <PDChatSDKFramework/PDChatSDKFramework.h>
//引入头文件
-(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{  
[PDChatManager shareManager].secretKey = @"您的Key";
……
}

3.进入后台或进入前台需要相应配置，代码如下
- (void)applicationDidEnterBackground:(UIApplication *)application {
[[PDChatManager shareManager] applicationDidEnterBackground:application];
}
- (void)applicationWillEnterForeground:(UIApplication *)application {
[[PDChatManager shareManager] applicationWillEnterForeground:application];
}

4.接入客户端功能（C端）
/**
登录服务器并进入聊天窗口

@param businessKey 商家key
@param visitSource 商家名字/项目名字
@param customerAccount 客户账号
@param customerNickname 客户昵称(非必传)
@param customerHeadUrl 客户头像(非必传)
@param viewController 当前控制器
@param pderror 错误信息
*/
- (void)pdchatUserLoginWithBusinessKey:(NSString *)businessKey withVisitSource:(NSString *)visitSource withCustomerAccount:(NSString *)customerAccount withCustomerNickname:(NSString *)customerNickname withCustomerHeadUrl:(NSString *)customerHeadUrl withCurrentViewController:(UIViewController *)viewController errorBlock:(void(^)(PDError *error))pderror;

具体错误码请查看PDError 

4.接入客服端功能（B端）
/**
登录服务器

@param loginAccount 登陆账号
@param loginPwd 登录密码
@param pderror 错误信息
*/
- (void)pdchatBusinessLoginWithBusinessAccount:(NSString *)loginAccount loginPwd:(NSString *)loginPwd errorBlock:(void(^)(PDError *error))pderror;

具体错误码请查看PDError 

/**
跳转到在线咨询列表

@param viewController 当前控制器
*/
- (void)pdchatBussinessIntoOnlineConsultationByCurrentViewController(UIViewController *)viewController;

Pod::Spec.new do |spec|
spec.name         = 'PDChatSDKFramework'
spec.version      = '1.1.1'
spec.license      = { :type => 'MIT' }
spec.homepage     = 'https://github.com/leajiang/PDChatSDKFramework'
spec.authors      = { "jiangle" => "649498510@qq.com" }
spec.summary      = 'jiangle.'
spec.source       = { :git => 'https://github.com/leajiang/PDChatSDKFramework.git', :tag =>'1.1.1'  }
spec.platform     = :ios, '8.0'
spec.vendored_frameworks = 'PDChatSDKFramework.framework','iflyMSC.framework'
spec.frameworks   = 'UIKit','AVFoundation','Foundation'
spec.resource = "Resources/PDChatResource.bundle"

spec.dependency 'XMPPFramework'
spec.dependency 'FMDB'
spec.dependency 'AFNetworking'
spec.dependency 'MBProgressHUD'
spec.dependency 'Masonry'
spec.dependency 'XMLReader'
spec.dependency 'YYModel'
spec.dependency 'SDWebImage'
spec.dependency 'MJRefresh'
spec.dependency 'DACircularProgress'
spec.dependency 'IQActionSheetPickerView'

spec.dependency 'AMap3DMap-NO-IDFA'
spec.dependency 'AMapSearch-NO-IDFA'
spec.dependency 'AMapLocation-NO-IDFA'
end

#1.标记tag
#2.配置文件
#3.创建账号 pod trunk register 邮箱 联系人 --description="描述" --verbose
#4.验证
#5.提交pod trunk push

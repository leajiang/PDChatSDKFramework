//
//  PDChatUser.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/2/18.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PDChatUser : NSObject
@property (copy, nonatomic) NSString *jid;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *avatar;
- (instancetype)initWithjid:(NSString *)jid withName:(NSString *)name withAvatar:(NSString *)avatar;
@end

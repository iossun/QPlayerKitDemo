//
//  QDataHandle.m
//  QPlayerKitDemo
//
//  Created by 孙慕 on 2022/7/11.
//  Copyright © 2022 Aaron. All rights reserved.
//

#import "QDataHandle.h"

@implementation QDataHandle

+ (QDataHandle *)shareInstance {
    
    static QDataHandle * single = nil;
    static dispatch_once_t onceToken ;
    
    dispatch_once(&onceToken, ^{
        single =[[QDataHandle alloc]init];
    }) ;
    return single;
    
}

-(instancetype)init{
    if (self = [super init]) {
        [self showPlayerConfiguration];
    }
    return self;
}


- (void)showPlayerConfiguration {
    NSUserDefaults *userdafault = [NSUserDefaults standardUserDefaults];
    NSArray *dataArray = [userdafault objectForKey:@"PLPlayer_settings"];
    
    if (dataArray.count != 0 ) {
        NSMutableArray *array = [NSMutableArray array];
        for (NSData *data in dataArray) {
            QNClassModel *classModel = [NSKeyedUnarchiver unarchiveObjectWithData:data];
            [array addObject:classModel];
        }
        _playerConfigArray = [array copy];
        
    } else {
        
//        NSDictionary *enableRenderDict = @{@"enableRender - 渲染画面 ( Default：YES )":@[@"NO", @"YES"], @"default":@1};
//        NSDictionary *backgroundPlayEnableDict = @{@"backgroundPlayEnable - 支持音频后台播放 ( Default：YES )":@[@"NO", @"YES"], @"default":@1};
//        NSDictionary *refererDict = @{@"referer - 设置 http header referer 值 ( Default：null )":@[@"null", @"pili", @"player"], @"default":@0};
//        NSDictionary *viewModeDict = @{@"contentMode - 设置 playerView 的填充方式 ( Default：UIViewContentModeScaleAspectFit )":@[@"UIViewContentModeScaleToFill", @"UIViewContentModeScaleAspectFit", @"UIViewContentModeScaleAspectFill"], @"default":@1};
//
//        NSArray *piliPlayerArray = @[enableRenderDict,backgroundPlayEnableDict,refererDict, viewModeDict];
//
//        NSDictionary *LogLevelDict = @{@"LogLevel - 控制台 log 的级别 ( Default：kPLLogNone )":@[@"kPLLogNone", @"kPLLogError", @"kPLLogWarning", @"kPLLogInfo", @"kPLLogDebug", @"kPLLogVerbose"], @"default":@0};
        NSDictionary *startDict = @{@"播放起始 (ms)":@[@"0.0",@"0.0"], @"default":@0};
        NSDictionary *videoToolboxDict = @{@"Decoder":@[@"自动",@"硬解",@"软解",@"混解"], @"default":@0};
        
        NSDictionary *seekDict = @{@"Seek":@[@"关键帧seek",@"精准seek"], @"default":@0};
        
        NSDictionary *actionDict = @{@"Start Action":@[@"启播播放",@"启播暂停"], @"default":@0};

        NSDictionary *renderDict = @{@"Render ratio":@[@"自动",@"拉伸",@"铺满",@"16:9",@"4:3"], @"default":@0};
        
        NSDictionary *speepDict = @{@"播放速度":@[@"0.5",@"0.75",@"1.0",@"1.25",@"2.0"], @"default":@2};
        
        NSDictionary *colorBDict = @{@"色盲模式":@[@"无",@"红色盲",@"绿色盲",@"蓝色盲"], @"default":@0};
        
        
        NSArray *piliOptionArray = @[startDict,videoToolboxDict, seekDict,actionDict,renderDict,speepDict,colorBDict];
        
//        NSDictionary *PLPlayerDict = @{@"PLPlayer":piliPlayerArray};
        NSDictionary *PLPlayerOptionDict = @{@"PLPlayerOption":piliOptionArray};
    
        NSArray *configureArray = @[PLPlayerOptionDict];

        // 装入属性配置数组
        _playerConfigArray = [QNClassModel classArrayWithArray:configureArray];
    }
}



@end

//
//  QPlayerKitDemoTests.m
//  QPlayerKitDemoTests
//
//  Created by 孙慕 on 2021/12/2.
//  Copyright © 2021 Aaron. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "PLPlayerKit.h"


NSString *PLPlayerUnitTestURL= @"https://image01.bckid.com.cn/video/operation/1634881377059_94328132.OP.mp4";

@interface QPlayerKitDemoTests : XCTestCase<PLPlayerDelegate>{

}

@property (nonatomic) QPlayer *player;
@property (nonatomic) XCTestExpectation* expect;
@end

@implementation QPlayerKitDemoTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
//    self.expect = [self expectationWithDescription:@"Oh, timeouta!"];
//    self.expect.assertForOverFulfill = NO;


}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
//    [_player dealloc];
}

-(void)testOpen{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;

    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];

    [self waitForExpectationsWithTimeout:6 handler:^(NSError * _Nullable error) {
    }];
}



-(void)testPlayEnable{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;
    self.player.enableRender = NO;
    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];
    
    [self waitForExpectationsWithTimeout:6 handler:^(NSError *error) {
        
    }];

}

-(void)testMediaPackets{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    [defaultOption setOptionValue:@(6) forKey:PLPlayerOptionKeyTimeoutIntervalForMediaPackets];
    
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;
    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];
    [self waitForExpectationsWithTimeout:6 handler:^(NSError *error) {
        
    }];
}

-(void)testBufferDuration{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    [defaultOption setOptionValue:@(1000) forKey:PLPlayerOptionKeyMaxL1BufferDuration];
    [defaultOption setOptionValue:@(200) forKey:PLPlayerOptionKeyMaxL2BufferDuration];
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;
    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];
    [self waitForExpectationsWithTimeout:6 handler:^(NSError *error) {
        
    }];
}

-(void)testSpeedAdjust{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    [defaultOption setOptionValue:@(NO) forKey:PLPlayerOptionKeyCacheBufferDurationSpeedAdjust];
    
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;
    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];
    [self waitForExpectationsWithTimeout:6 handler:^(NSError *error) {
        
    }];
}

-(void)testVideoToolbox{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    [defaultOption setOptionValue:@(YES) forKey:PLPlayerOptionKeyVideoToolbox];
    
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;
    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];
    [self waitForExpectationsWithTimeout:6 handler:^(NSError *error) {
        
    }];
}

-(void)testPlayerOptionKeyLogLevel{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    [defaultOption setOptionValue:@(kPLLogDebug) forKey:PLPlayerOptionKeyLogLevel];
    
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;
    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];
    [self waitForExpectationsWithTimeout:6 handler:^(NSError *error) {
        
    }];
}


-(void)testAPI{
    self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
    self.expect.assertForOverFulfill = NO;
    
    PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
    self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
    self.player.delegate = self;
    
    NSURL *videoUrl = [NSURL URLWithString:PLPlayerUnitTestURL];
    [_player playWithURL:videoUrl sameSource:NO];
    [self waitForExpectationsWithTimeout:6 handler:^(NSError *error) {
        
    }];
    XCTAssertNotNil(_player.URL,"url is nil");
    NSLog(@"test----当前播放器状态---%ld",(long)_player.status);
    NSLog(@"test----是否处于正在播放状态---%ld",(long)_player.playing);
    NSLog(@"test----UIView 对象---%ld",(long)_player.playerView);
    NSLog(@"test----连接时间--%ld",(long)_player.connectTime);
    NSLog(@"test----首开时间--%ld",(long)_player.firstVideoTime);
    NSLog(@"test----width-%ld",(long)_player.width);
    NSLog(@"test----height-%ld",(long)_player.height);
    XCTAssertTrue(_player.width != 0,@"info error");
    XCTAssertTrue(_player.height != 0,@"info error");
    NSLog(@"test----rtmpVideoTimeStamp-ld",CMTimeGetSeconds(_player.rtmpVideoTimeStamp));
    NSLog(@"test----rtmpAudioTimeStamp-%ld",CMTimeGetSeconds(_player.rtmpAudioTimeStamp));
    NSLog(@"test----videoRotate-%ld",(long)_player.rotate);
    
    _player.DRMKey = @"qqq";
    _player.playSpeed = 1.0;
    _player.videoClipFrame = CGRectMake(1, 1, 100, 100);
    _player.loopPlay = YES;
    
    [_player pause];
    sleep(1);
    [_player resume];
    sleep(1);
    [_player stop];
    XCTAssertTrue([_player play],@"开始播放");
    XCTAssertTrue(_player.videoFPS != 0,@"info error");
    XCTAssertTrue(_player.videoBitrate != 0,@"info error");
    XCTAssertTrue(_player.audioFPS != 0,@"info error");
    XCTAssertTrue(_player.audioBitrate != 0,@"info error");
    NSLog(@"test----videoFPS-%ld",(long)_player.videoFPS);
    NSLog(@"test----videoBitrate-%ld",(long)_player.videoBitrate);
    NSLog(@"test----audioFPS-%ld",(long)_player.audioFPS);
    NSLog(@"test----audioBitrate-%ld",(long)_player.audioBitrate);

    [_player seekTo:CMTimeMake(10000, 1000)];
    
    sleep(0.5);
    [_player setVolume:0.5];
    sleep(0.5);
    [_player setVolume:1.0];
    sleep(0.5);
    [_player setVolume:1.5];
    sleep(0.5);
    [_player setVolume:2.5];
    
    [_player setBufferingEnabled:NO];
    NSLog(@"test----getHttpBufferSize-%ld",(long)_player.getHttpBufferSize);
}


-(void)testAllVideoSource{

    NSString *test0 = [[NSBundle mainBundle] pathForResource:@"source264_mp4" ofType:@"mp4"];
    NSString *test1 = [[NSBundle mainBundle] pathForResource:@"source265_mp4" ofType:@"mp4"];
    NSString *test2 = [[NSBundle mainBundle] pathForResource:@"source264_flv" ofType:@"flv"];
    NSString *test3 = [[NSBundle mainBundle] pathForResource:@"source265_flv" ofType:@"flv"];
    NSString *test4 = [[NSBundle mainBundle] pathForResource:@"source_aac" ofType:@"aac"];
    
    NSArray *urlArray = @[test0,test1,test2,test3,test4];
    for (int i = 0; i < urlArray.count; i ++) {
        self.expect = [self expectationWithDescription:@"Oh, timeoutaaaa!"];
        self.expect.assertForOverFulfill = NO;
        
        PLPlayerOption *defaultOption = [PLPlayerOption defaultOption];
        self.player = [[PLPlayer alloc]initWithURL:nil option:defaultOption];
        self.player.delegate = self;
        NSURL *videoUrl = [NSURL URLWithString:urlArray[i]];
        [_player playWithURL:videoUrl sameSource:NO];
        [self waitForExpectationsWithTimeout:10 handler:^(NSError * _Nullable error) {
        }];
    }
}

-(void)player:(QPlayer *)player firstRender:(PLPlayerFirstRenderType)firstRenderType{
        [self.expect fulfill];
}

-(void)player:(QPlayer *)player stoppedWithError:(NSError *)error{
    XCTAssertNotNil(error,"play error stop");
}

@end

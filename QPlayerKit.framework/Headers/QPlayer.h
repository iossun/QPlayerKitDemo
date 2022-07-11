
//
//  QPlayer.h
//  QPlayer
//
//  Created by 孙慕 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <UIKit/UIKit.h>
#import "QIOSCommon.h"
#import "QMediaItem.h"

NS_ASSUME_NONNULL_BEGIN
@class QPlayer;
@class QMediaItem;
@protocol  QPlayerDelegate <NSObject>

- (void)player:(QPlayer *_Nullable)player stateChanged:(QPlayerStatus)state;


- (void)player:(QPlayer *_Nullable)player streamOpen:(QNotifyModle *)notify duration:(int64_t)duration;


- (void)player:(QPlayer *_Nullable)player streamOpenError:(QNotifyModle *)notify error:(NSInteger)error;

- (void)player:(QPlayer *_Nullable)player streamIOError:(QNotifyModle *)notify;

- (void)player:(QPlayer *_Nullable)player streamConnectStart:(QNotifyModle *)notify purl:(NSString *)purl retryTime:(NSInteger)retryTime;

- (void)player:(QPlayer *_Nullable)player streamConnectEnd:(QNotifyModle *)notify purl:(NSString *_Nonnull)purl retryTime:(NSInteger)retryTime;

- (void)player:(QPlayer *_Nullable)player renderProgress:(QNotifyModle *)notify progress:(NSInteger)progress;

- (void)player:(QPlayer *_Nullable)player renderBufferingChange:(QNotifyModle *)notify;

- (void)player:(QPlayer *_Nullable)player screenRenderFirstFrame:(QNotifyModle *)notify elapsedTime:(NSInteger)elapsedTime;

- (void)player:(QPlayer *_Nullable)player FPSDidChanged:(NSInteger)fps;

- (void)player:(QPlayer *_Nullable)player bitrateDidChanged:(NSInteger)bitrate;

- (void)player:(QPlayer *_Nullable)player downloadProcess:(NSInteger)downloadSpeed bufferPos:(NSInteger)bufferPos;

- (void)player:(QPlayer *_Nullable)player eventLoopNotAllow:(QNotifyModle *)notify commandName:(NSString *)commandName;

- (void)player:(QPlayer *_Nullable)player qualitySwitchStart:(QNotifyModle *)notify oldQuality:(NSInteger)oldQuality newQuality:(NSInteger)newQuality qualitySerial:(NSInteger)qualitySerial;

- (void)player:(QPlayer *_Nullable)player qualityVideoDidChanged:(QNotifyModle *)notify oldQuality:(NSInteger)oldQuality newQuality:(NSInteger)newQuality qualitySerial:(NSInteger)qualitySerial;
- (void)player:(QPlayer *_Nullable)player qualityAudioDidChanged:(QNotifyModle *)notify oldQuality:(NSInteger)oldQuality newQuality:(NSInteger)newQuality qualitySerial:(NSInteger)qualitySerial;

- (void)player:(QPlayer *_Nullable)player qualitySwitchFailed:(QNotifyModle *)notify oldQuality:(NSInteger)oldQuality newQuality:(NSInteger)newQuality qualitySerial:(NSInteger)qualitySerial ;

- (void)player:(QPlayer *_Nullable)player qualitySwitchCanceld:(QNotifyModle *)notify oldQuality:(NSInteger)oldQuality newQuality:(NSInteger)newQuality qualitySerial:(NSInteger)qualitySerial;

- (void)player:(QPlayer *_Nullable)player qualitySwitchRetryLater:(QNotifyModle *)notify;

- (void)player:(QPlayer *_Nullable)player speedDidChange:(float)speed;

- (void)player:(QPlayer *_Nullable)player videoDecodeType:(NSInteger)type;

@end

@interface QStreamElement : NSObject

@property (strong, nonatomic) NSString *user_type;
@property (assign, nonatomic) QPlayerURLType url_type;
@property (strong, nonatomic) NSString *url;
@property (assign, nonatomic) int quality;
@property (assign, nonatomic) BOOL is_select;
@property (copy, nonatomic) NSString *backup_url;
@property (copy, nonatomic) NSString *referer;
@property (assign, nonatomic) QPlayerRenderType renderType;
@property (assign, nonatomic) BOOL immediately;



@end

@interface QMediaModel : NSObject

@property (strong, nonatomic) NSArray <QStreamElement*> *streamElements;
@property (assign, nonatomic) BOOL is_live;

@end


@interface QPlayer : NSObject

@property(weak,nonatomic)id<QPlayerDelegate> mDelagete;

/**
 QPlayer 的画面输出到该 UIView 对象
 
 @since v1.0.0
 */
@property (nonatomic, strong, nullable, readonly) UIView *playerView;

/**
 指示当前 PLPlayer 是否处于正在播放状态
 
 @since v1.0.0
 */
@property (nonatomic, assign, readonly, getter=isPlaying) BOOL  playing;

///**
// 支持音频后台播放的开关, 默认为 YES. 请确认 [AVAudioSession canPlayInBackground] 为 YES。
// 
// @warning 当设置允许后台播放时，建议 iOS 9 及以下系统，在 AppDelegate.m 下的即将进入后台： - (void)applicationWillResignActive:(UIApplication *)application 里，设置 enableRender 为 NO 以取消画面渲染；已经进入前台：- (void)applicationDidBecomeActive:(UIApplication *)application 里，设置 enableRender 为 YES 以恢复画面渲染
// 
// @since v1.0.0
// */
//@property (nonatomic, assign, getter=isBackgroundPlayEnable) BOOL backgroundPlayEnable;
// 当前播放状态
@property (nonatomic, assign, readonly) QPlayerStatus  currentPlayerState;

// 当前位置 ms
@property (nonatomic, assign, readonly) long  currentPosition;

// 视频长度 ms
@property (nonatomic, assign, readonly) long duration;

// 下载速率 b/s
@property (nonatomic, assign, readonly) long downloadSpeed;

// 缓存大小 ms
@property (nonatomic, assign, readonly) long bufferPostion;

// 当前 fps
@property (nonatomic, assign, readonly) int fps;

//当前码率
@property (nonatomic, assign, readonly) int biteRate;

//设置播放器速率
@property (nonatomic, assign) float speed;

/**
 首开时间
 从触发播放到第一帧视频渲染的耗时
 
 @since v2.4.3
 */

@property (nonatomic, assign, readonly) int firstVideoTime;



+(instancetype)new NS_UNAVAILABLE;

-(instancetype)init NS_UNAVAILABLE;

-(instancetype)initPlayerAppInfo:(QAppInformation *)appInfo storageDir:(NSString *)storageDir logLevel:(QPlayerLogLevel)log_level;

/**
 * 暂停渲染
 * @return true: 调用成功 false: 调用失败
 */
-(BOOL)pause_render;

/**
 * 在暂停渲染状态下 恢复渲染
 * @return true: 调用成功 false: 调用失败
 */
-(BOOL)resume_render;

/**
 * 停止当前视频播放
 * @return true: 调用成功 false: 调用失败
 */
-(BOOL)stop;

/*** 播放音视频资源
 * @param pmedia_model 音视频资源
 * @param start_pos 起播时间戳 毫秒
 */
-(BOOL)playMediaModel:(QMediaModel*)pmedia_model startPos:(int64_t)start_pos;


/*** 播放预加载资源
 * @param mediaItem 预加载实例
 */
-(BOOL)playMediaItem:(QMediaItem*)mediaItem;

/*** 设置播放音量
 * @param volume 需要设置0~100，默认100
 */
- (void)setVolume:(int)volume;

/***
 * 设置视频渲染比例
 * @param ratio see[QPlayerSetting.QPlayerRenderRatio]
 * @return true 设置成功 false 设置失败
 */
-(BOOL)setRenderRatio:(QPlayerRenderRatio)ratio;

/***
 * 设置VR视频的旋转角度
 * @param rotateX 横向角度 （360度制）
 * @return rotateY 纵向角度 （360度制）
 */

-(BOOL)setPanoramaViewRotate:(float)rotateX rotateY:(float)rotateY;

/*** 设置解码方式
 * @param type 解码方式
 */
-(BOOL)setDecoderType:(QPlayerDecoderType)type;

/*** 设置起播方式
 * @param action 起播方式
 */
-(BOOL)setStartAction:(int)action;

/*** 设置seek方式
 * @param mode seek方式
 */
-(BOOL)setSeekMode:(QPlayerSeekMode)mode;

/***
 * 设置色觉优化
 * @param type
 * @return true 设置成功 false 设置失败
 */
-(BOOL)setBlindType:(QPlayerBlindType)type;

-(BOOL)setLogLevel:(QPlayerLogLevel)level;

/**
 * 切换视频当前进度
 * @param position 切换到哪个时间点 单位：毫秒
 */
-(BOOL)seek:(int64_t)position;

/**
 * 切换视频分辨率
 * @param streamElement 资源模型
 *  @return true 调用成功， false 调用失败
 */
-(BOOL)switchQuality:(QStreamElement *)streamElement;

NS_ASSUME_NONNULL_END
@end


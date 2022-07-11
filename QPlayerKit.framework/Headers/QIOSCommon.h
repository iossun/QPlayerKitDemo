//
//  QIOSCommon.h
//  qplayer2-core
//
//  Created by 孙慕 on 2022/5/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, QPlayerStatus){
    QPLAYERSTATUS_NONE = 0,       //初始状态
    QPLAYERSTATUS_INIT = 1,       //播放器开始创建各种对象 没有对应的state 创建完对象就上报这个状态
    QPLAYERSTATUS_PREPARE = 2,  //开始拉视频数据解码变换等，重新换地址后，都走这个状态
//    QPLAYERSTATUS_FIRST_FRAME_PAUSE = 3,   //首帧暂停
    QPLAYERSTATUS_PLAYING = 4,    //播放中
    QPLAYERSTATUS_PAUSED = 5,     //用户暂停
    QPLAYERSTATUS_PAUSED_RENDER = 6, //暂停渲染
    QPLAYERSTATUS_COMPLETED = 7,  //播放完成
    QPLAYERSTATUS_SEEKING = 8,    //SEEK
    //TODO
    QPLAYERSTATUS_STOPPED = 9, //停止当前播放的视频
    QPLAYERSTATUS_ERROR = 10, //播放出错（是否需要分 可恢复 和 不可恢复 ）
    QPLAYERSTATUS_END = 11, //播放器释放各种对象完成
    QPLAYERSTATUS_MEDIA_ITEM_PREPARE = 12, //开始拉视频数据解码变换等，重新换地址后，都走这个状态 针对Media Item的play 方式
    QPLAYERSTATUS_RELEASE = 13, //播放器结束，且释放各类资源
};
typedef NS_ENUM(NSInteger, QPlayerAVMediaType){
    QPLAYER_AVMEDIA_TYPE_UNKNOWN = -1,  ///< Usually treated as AVMEDIA_TYPE_DATA
    QPLAYER_AVMEDIA_TYPE_VIDEO,
    QPLAYER_AVMEDIA_TYPE_AUDIO,
    QPLAYER_AVMEDIA_TYPE_DATA,          ///< Opaque data information usually continuous
    QPLAYER_AVMEDIA_TYPE_SUBTITLE,
    QPLAYER_AVMEDIA_TYPE_ATTACHMENT,    ///< Opaque data information usually sparse
    QPLAYER_AVMEDIA_TYPE_NB
};
typedef NS_ENUM(NSInteger, QPlayerURLType){
    QPLAYER_QAUDIO_AND_VIDEO = 0,
    QPLAYER_QAUDIO,
    QPLAYER_QVIDEO,
    QPLAYER_QURLType_INVALID,
};

typedef NS_ENUM(NSInteger, QPlayerRenderType){
//    QRT_NONE =-1,
    QRT_PLANE = 0,
    QRT_PANORAMA_EQUIRECT_ANGULAR = 1,
//    QRT_PANORAMA_ANGULAR_CUBEMAP = 2,
};




typedef NS_ENUM(NSInteger, QPlayerNotifyType) {
    QPLAYER_NOTIFY_NONE,
    /************** moudle screen render *******************/
    //一个视频的首个start标志帧（不含数据）
    QPLAYER_NOTIFY_SCREEN_RENDER_START = 10001,
    //一个视频的第一帧渲染完成（含数据）
    QPLAYER_NOTIFY_SCREEN_RENDER_FIRST_FRAME = 10002,
    QPLAYER_NOTIFY_SCREEN_RENDER_END = 10003,

    QPLAYER_NOTIFY_SCREEN_RENDER_OVER_ONE_FRAME = 10006,

    QPLAYER_NOTIFY_SCREEN_RENDER_INIT_ERROR = 10007,


    /************** moudle video render *******************/

    //该progress 为视频的progress 内部使用

    QPLAYER_NOTIFY_VIDEO_RENDER_PROGRESS = 11001,
    QPLAYER_NOTIFY_VIDEO_RENDER_END = 11002,
    QPLAYER_NOTIFY_VIDEO_RENDER_SUCCESS = 11003,
    QPLAYER_NOTIFY_VIDEO_RENDER_QUALITY_CHANGED =11004,



    QPLAYER_NOTIFY_INTERNAL_VIDEO_RENDER_NO_DATA = 11101,

    /************** moudle audio render *******************/

    QPLAYER_NOTIFY_AUDIO_RENDER_START = 12002,
    QPLAYER_NOTIFY_AUDIO_RENDER_END = 12003,
//        QPLAYER_NOTIFY_AUDIO_RENDER_SUCCESS = 12004,

    //        QPLAYER_NOTIFY_AUDIO_RENDER_BUFFERRING_START = 30004,
//        QPLAYER_NOTIFY_AUDIO_RENDER_BUFFERRING_END = 30005,
    //该progress 为音频的progress 内部使用

    QPLAYER_NOTIFY_AUDIO_RENDER_PROGRESS = 12006,
    QPLAYER_NOTIFY_AUDIO_RENDER_QUALITY_CHANGED = 12007,


    QPLAYER_NOTIFY_INTERNAL_AUDIO_RENDER_NO_DATA = 12101,

    /************** combine render *******************/

    QPLAYER_NOTIFY_RENDER_BUFFERRING_START = 13000,
    QPLAYER_NOTIFY_RENDER_BUFFERRING_END = 13001,

    //该progress 为音视频合并的progress 并且是上抛给上层的
    QPLAYER_NOTIFY_RENDER_PROGRESS = 13002,

    /************** moudle input stream *******************/
    QPLAYER_NOTIFY_INPUT_STREAM_INVALID_URL = 40001,

    QPLAYER_NOTIFY_INPUT_STREAM_OPEN = 40002,
    QPLAYER_NOTIFY_INTERNAL_INPUT_STREAM_CACHE_INCREASE = 40003,
    QPLAYER_NOTIFY_INTERNAL_INPUT_STREAM_CACHE_DECREASE = 40004,



    QPLAYER_NOTIFY_INPUT_STREAM_QUALITY_SWITCH_START = 40010,
    //todo move to render
    QPLAYER_NOTIFY_INPUT_STREAM_QUALITY_SWITCH_COMPLETE = 40011,
    QPLAYER_NOTIFY_INPUT_STREAM_QUALITY_SWITCH_FAILED = 40012,
    QPLAYER_NOTIFY_INPUT_STREAM_QUALITY_SWITCH_CANCELED = 40013,
    QPLAYER_NOTIFY_INPUT_STREAM_QUALITY_SWITCH_RETRY_LATER = 40014,

    QPLAYER_NOTIFY_INPUT_STREAM_IO_ERROR = 40100,
    QPLAYER_NOTIFY_INPUT_STREAM_OPEN_ERROR = 40101,
    QPLAYER_NOTIFY_INPUT_STREAM_INVALID_DATA_ERROR = 40102,
    QPLAYER_NOTIFY_INPUT_STREAM_RECONNECT_START = 40103,
    QPLAYER_NOTIFY_INPUT_STREAM_RECONNECT_END = 40104,

    QPLAYER_NOTIFY_INPUT_STREAM_HTTP_OPEN_START = 40110,
    QPLAYER_NOTIFY_INPUT_STREAM_HTTP_OPEN_END = 40111,
    QPLAYER_NOTIFY_INPUT_STREAM_TCP_OPEN_START = 40112,
    QPLAYER_NOTIFY_INPUT_STREAM_TCP_OPEN_END = 40113,



    QPLAYER_NOTIFY_INPUT_STREAM_INTERNAL_QUALITY_SWITCH_OLD_STREAM_FINISH = 40100,

    /************** moudle decoder *******************/
    QPLAYER_NOTIFY_DECODE_FINISH = 50001,

    QPLAYER_NOTIFY_INTERNAL_DECODE_CACHE_INCREASE = 50002,
    QPLAYER_NOTIFY_INTERNAL_DECODE_CACHE_DECREASE = 50003,

    QPLAYER_NOTIFY_DECODE_INIT_ERROR = 50004,
    QPLAYER_NOTIFY_DECODE_VIDEO_DECODE_TYPE = 50005,

    /************** state manager *******************/
    /** error **/
    QPLAYER_NOTIFY_STATE_MANAGER_CHANGE_STATE_NOT_ALLOW_ERROR = 60001,
    QPLAYER_NOTIFY_STATE_SEEKING_FAILED = 61001,
    QPLAYER_NOTIFY_STATE_PREPARE_START_SEEK_FAILED = 62001,

    QPLAYER_NOTIFY_STATE_ERROR_CODE = 62002,


    /************** render transformer *******************/
    QPLAYER_NOTIFY_INTERNAL_RENDER_TRANSFORMER_CACHE_INCREASE = 70000,
    QPLAYER_NOTIFY_INTERNAL_RENDER_TRANSFORMER_CACHE_DECREASE = 70001,

    QPLAYER_NOTIFY_RENDER_TRANSFORMER_INIT_ERROR = 70002,



    /************** Detect *******************/
    QPLAYER_NOTIFY_DETECT_DOWNLOADING = 80000,
    QPLAYER_NOTIFY_DETECT_FPS = 80001,
    QPLAYER_NOTIFY_DETECT_BITRATE = 80002,


    /************** event loop *******************/
    QPLAYER_NOTIFY_EVENT_LOOP_COMMOND_NOT_ALLOW = 90000,


    /************** clock *******************/
    QPLAYER_NOTIFY_EVENT_SPEED_CHANGE = 100000,

    QPLAYER_NOTIFY_CLOCK_OUT_SYNC = 100001,

};


typedef NS_ENUM(NSInteger, QPlayerRenderRatio) {
    QPLAYER_RATIO_SETTING_AUTO = 1,
    QPLAYER_RATIO_SETTING_FULL_SCREEN,
    QPLAYER_RATIO_SETTING_STRETCH,
    QPLAYER_RATIO_SETTING_16_9,
    QPLAYER_RATIO_SETTING_4_3,

};

typedef NS_ENUM(NSInteger, QPlayerDecoderType) {
    QPLAYER_DECODER_SETTING_AUTO = 0,
    QPLAYER_DECODER_SETTING_HARDWARE_PRIORITY,
    QPLAYER_DECODER_SETTING_SOFT_PRIORITY,
    QPLAYER_DECODER_SETTING_FIRST_FRAME_ACCEL_PRIORITY,
};


typedef NS_ENUM(NSInteger, QPlayerSeekMode) {
    QPLAYER_SEEK_SETTING_NORMAL = 0,
    QPLAYER_SEEK_SETTING_ACCURATE,
};

typedef NS_ENUM(NSInteger, QPlayerBlindType) {
    QPLAYER_BLIND_SETTING_NONE=0,
    QPLAYER_BLIND_SETTING_RED,
    QPLAYER_BLIND_SETTING_GREEN,
    QPLAYER_BLIND_SETTING_BLUE,
};

typedef NS_ENUM(NSInteger, QPlayerLogLevel){
    LOG_QUIT = 0,
    LOG_ERROR = 1,
    LOG_WARNING = 2,
    LOG_DEBUG = 3,
    LOG_INFO = 4,
    LOG_VERBOSE = 5
};


@interface QNotifyModle : NSObject
@property (assign, nonatomic) QPlayerNotifyType notify_type;
@property (strong, nonatomic) NSString *user_type;
@property (assign, nonatomic) QPlayerURLType url_type;
@property (assign, nonatomic) int quality;
@property (assign, nonatomic) int stream_id;
@property (assign, nonatomic) int stream_index;
@property (assign, nonatomic) QPlayerAVMediaType media_type;


+(QNotifyModle *)getNewModleUser_type:(NSString *)user_type url_type:(QPlayerURLType)url_type quality:(int)quality stream_id:(int)stream_id stream_index:(int)stream_index media_type:(QPlayerAVMediaType)media_type notify_type:(QPlayerNotifyType)notify_type;

+(QNotifyModle *)defaultModle;

@end


@interface QAppInformation : NSObject
@property (copy, nonatomic) NSString *mAppId;

@property (copy, nonatomic) NSString *mAuthorId;

@property (copy, nonatomic) NSString *mAppVersion;
@end


@interface QIOSCommon : NSObject

+ (NSString *)getDeviceName;

+ (NSString *)getSystemVersion;

+ (NSString *)getUUID;

@end

NS_ASSUME_NONNULL_END

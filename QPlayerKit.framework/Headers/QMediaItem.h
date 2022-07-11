//
//  QMediaItem.h
//  QPlayerKit
//
//  Created by 孙慕 on 2022/7/7.
//

#import <Foundation/Foundation.h>
#import "QPlayer.h"
#include "QIOSCommon.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, QMediaItemState) {
    QMEDIAITEM_STATE_NONE = 100,//初始状态
    QMEDIAITEM_STATE_PREPARE,
    QMEDIAITEM_STATE_LOADING,
    QMEDIAITEM_STATE_PAUSED,
    QMEDIAITEM_STATE_STOPED,
    QMEDIAITEM_STATE_ERROR,
    QMEDIAITEM_STATE_StatePREPARE_USE,
    QMEDIAITEM_STATE_USED,
    QMEDIAITEM_STATE_DISCARD,
};


typedef NS_ENUM(NSInteger, QMediaItemNotify) {
    QMEDIAITENOTIFY_INPUT_STREAM_OPEN = 40002,
    QMEDIAITEMINPUT_STREAM_IO_ERROR = 40005,
    QMEDIAITEMINPUT_STREAM_OPEN_ERROR = 40006,
};
@class QMediaItem;
@class QMediaModel;
@class QIOSMediaItem;

@protocol QMediaItemDelegate <NSObject>

-(void)mediaItem:(QMediaItem *)mediaItem onStateChanged:(QMediaItemState)state;

-(void)mediaItem:(QMediaItem *)mediaItem openNotify:(QNotifyModle *)notify duration:( int64_t)duration;

-(void)mediaItem:(QMediaItem *)mediaItem openError:(QNotifyModle *)notify;

-(void)mediaItem:(QMediaItem *)mediaItem ioError:(QNotifyModle *)notify;

-(void)mediaItem:(QMediaItem *)mediaItem notAllow:(QNotifyModle *)notify command_name:(NSString *)command_name mediaItemState:(QMediaItemState)state;

@end

@interface QMediaItem : NSObject<QMediaItemDelegate>

@property(weak,nonatomic)id<QMediaItemDelegate> mDelagete;

@property(nonatomic,readonly)QMediaModel *media_model;

-(instancetype)initItemComtextStorageDir:(NSString *)storageDir logLevel:(QPlayerLogLevel)log_level;

/**
 * 开始预加载
 * @return true: start成功 false: start 失败
 */
-(BOOL)start:(QMediaModel *)media_model startPos:(int64_t)start_pos;

/**
 * 暂停预加载
 * @return true: pause成功 false: pause失败
 */
-(BOOL)pause;

/**
 * 如果之前是暂停状态 ，那么调用resume 则恢复下载
 * @return true: resume成功 false: resume失败
 */
-(BOOL)resume;

/**
 * 停止预加载，结束当前预加载实例的生命周期 停止后调用其他接口就无效了，
 * @return true: stop成功 false: stop失败
 */
-(BOOL)stop;


-(void *)getCoreImpl;

@end

NS_ASSUME_NONNULL_END

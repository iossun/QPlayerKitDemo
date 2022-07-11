//
//  QNPlayerMaskView.h
//  QPlayerKitDemo
//
//  Created by 冯文秀 on 2017/9/28.
//  Copyright © 2017年 qiniu. All rights reserved.
//

#import <UIKit/UIKit.h>
@class QNPlayerMaskView;
@protocol QNPlayerMaskViewDelegate <NSObject>

/**
 点击 QNPlayerMaskView 返回按钮的回调

 @param playerMaskView QNPlayerMaskView 的实例
 @param backButton 返回按钮
 */
- (void)playerMaskView:(QNPlayerMaskView *)playerMaskView didGetBack:(UIButton *)backButton;


/**
 点击放大／缩小 QNPlayerMaskView 屏幕按钮的结果回调

 @param playerMaskView QNPlayerMaskView 的实例
 @param isLandscape 是否是横屏状态
 */
- (void)playerMaskView:(QNPlayerMaskView *)playerMaskView isLandscape:(BOOL)isLandscape;


@end

@interface QNPlayerMaskView : UIView

@property (nonatomic, assign) id<QNPlayerMaskViewDelegate> delegate;
@property (nonatomic, assign) BOOL isLiving;

/** QPlayer **/
@property (nonatomic, weak) QPlayer *player;

@property (nonatomic, strong) UIButton *playButton;
@property (nonatomic, strong) UIButton *settingButton;
@property (nonatomic, strong) UISlider *volumeSlider;
@property (nonatomic, strong) UIButton *shootButton;
@property (nonatomic, strong) UIButton *clipButton;
@property (nonatomic, strong) UIButton *rotateButton;
@property (nonatomic, strong) UIButton *mirrorButton;

@property (nonatomic, strong) UISegmentedControl *qualitySegMc;



/**
 QNPlayerMaskView 初始化方法

 @param frame QNPlayerMaskView 的位置及大小
 @param player PLPlayer 的实例
 @param isLiving 是否是直播
 @return QNPlayerMaskView 的实例子
 */
- (id)initWithFrame:(CGRect)frame player:(QPlayer *)player isLiving:(BOOL)isLiving;


/**
 刷新音量图片的显示
 */
- (void)updateVoulmeSliderImage;


/**
 添加加载动画
 */
- (void)loadActivityIndicatorView;


/**
 停止加载动画
 */
- (void)removeActivityIndicatorView;

@end

//
//  BSNumbersView.h
//  BSNumbersSample
//
//  Created by 张亚东 on 16/4/6.
//  Copyright © 2016年 blurryssky. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, BSNumbersSeparatorStyle) {
    BSNumbersSeparatorStyleNone,
    BSNumbersSeparatorStyleReal,
    BSNumbersSeparatorStyleDotted
};

@class BSNumbersView;

NS_ASSUME_NONNULL_BEGIN

@protocol BSNumbersViewDelegate <NSObject>

@optional

- (nullable NSAttributedString *)numbersView:(BSNumbersView *)numbersView
        attributedStringAtIndexPath:(NSIndexPath *)indexPath;

- (nullable UIView *)numbersView:(BSNumbersView *)numbersView
                 viewAtIndexPath:(NSIndexPath *)indexPath;

- (void)numbersView:(BSNumbersView *)numbersView
                 didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface BSNumbersView : UIView

@property (assign, nonatomic) id<BSNumbersViewDelegate> delegate;

///min width for each item
@property (assign, nonatomic) CGFloat itemMinWidth;

///max width for each item
@property (assign, nonatomic) CGFloat itemMaxWidth;

///height for each item
@property (assign, nonatomic) CGFloat itemHeight;

///text horizontal margin for each item, default is 10.0
@property (assign, nonatomic) CGFloat horizontalItemTextMargin;

///the column need to freeze
@property (assign, nonatomic) NSInteger freezeColumn;

///header font
@property (strong, nonatomic) UIFont *headerFont;

///header text color
@property (strong, nonatomic) UIColor *headerTextColor;

///header background color
@property (strong, nonatomic) UIColor *headerBackgroundColor;

///body font
@property (strong, nonatomic) UIFont *slideBodyFont;

///body text color
@property (strong, nonatomic) UIColor *slideBodyTextColor;

///body background color
@property (strong, nonatomic) UIColor *slideBodyBackgroundColor;

///body font
@property (strong, nonatomic) UIFont *freezeBodyFont;

///body text color
@property (strong, nonatomic) UIColor *freezeBodyTextColor;

///body background color
@property (strong, nonatomic) UIColor *freezeBodyBackgroundColor;

///separator
@property (assign, nonatomic) BSNumbersSeparatorStyle horizontalSeparatorStyle;

///default is [UIColor LightGrayColor]
@property (strong, nonatomic) UIColor *horizontalSeparatorColor;
@property (strong, nonatomic) UIColor *verticalSeparatorColor;

///data
@property (strong, nonatomic) NSArray<NSString *> *headerData;
@property (strong, nonatomic) NSArray<NSObject *> *bodyData;


- (NSString *)textAtIndexPath:(NSIndexPath *)indexPath;

- (CGSize)sizeForRow:(NSInteger)row;

- (void)reloadData;

NS_ASSUME_NONNULL_END

@end

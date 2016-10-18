//
//  Created by Lunar on 16/10/18.
//  Copyright © 2016年 Lunar. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "UIColor+FlatUI.h"

@protocol JYCalendarDelegate;

@interface CKDateItem : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *selectedBackgroundColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *selectedTextColor;

@end

typedef enum {
    startSunday = 1,
    startMonday = 2,
} CKCalendarStartDay;

@interface JYCalendarView : UIView

- (id)initWithStartDay:(CKCalendarStartDay)firstDay;
- (id)initWithStartDay:(CKCalendarStartDay)firstDay frame:(CGRect)frame;

//===== test =====
@property (nonatomic,strong) NSDictionary *remainStockDic;   //余票 key:date value:stock

@property (nonatomic) CKCalendarStartDay calendarStartDay;
@property (nonatomic, strong) NSLocale *locale;

@property (nonatomic, readonly) NSArray *datesShowing;

@property (nonatomic) BOOL onlyShowCurrentMonth;
@property (nonatomic) BOOL adaptHeightToNumberOfWeeksInMonth;

@property (nonatomic, weak) id<JYCalendarDelegate> delegate;

// Theming
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIFont *dateOfWeekFont;
@property (nonatomic, strong) UIColor *dayOfWeekTextColor;
@property (nonatomic, strong) UIFont *dateFont;

- (void)setMonthButtonColor:(UIColor *)color;
- (void)setInnerBorderColor:(UIColor *)color;
- (void)setDayOfWeekBottomColor:(UIColor *)bottomColor topColor:(UIColor *)topColor;

- (void)selectDate:(NSDate *)date makeVisible:(BOOL)visible;
- (void)reloadData;
- (void)reloadDates:(NSArray *)dates;

// Helper methods for delegates, etc.
- (BOOL)date:(NSDate *)date1 isSameDayAsDate:(NSDate *)date2;
- (BOOL)dateIsInCurrentMonth:(NSDate *)date;

@end

@protocol JYCalendarDelegate <NSObject>

@optional
- (void)calendar:(JYCalendarView *)calendar configureDateItem:(CKDateItem *)dateItem forDate:(NSDate *)date;
- (BOOL)calendar:(JYCalendarView *)calendar willSelectDate:(NSDate *)date;
- (void)calendar:(JYCalendarView *)calendar didSelectDate:(NSDate *)date;
- (BOOL)calendar:(JYCalendarView *)calendar willDeselectDate:(NSDate *)date;
- (void)calendar:(JYCalendarView *)calendar didDeselectDate:(NSDate *)date;

- (BOOL)calendar:(JYCalendarView *)calendar willChangeToMonth:(NSDate *)date;
- (void)calendar:(JYCalendarView *)calendar didChangeToMonth:(NSDate *)date;

- (void)calendar:(JYCalendarView *)calendar didLayoutInRect:(CGRect)frame;

- (void)calendarHeight:(CGFloat)height;

@end

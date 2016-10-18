//
//  ViewController.m
//  CalendarView
//
//  Created by Lunar on 16/10/18.
//  Copyright © 2016年 Lunar. All rights reserved.
//

#import "ViewController.h"
#import "JYCalendarView.h"

@interface ViewController ()<JYCalendarDelegate>

@property (weak, nonatomic) IBOutlet JYCalendarView *calendarView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *calendarHeight;

//=======test===========
@property(nonatomic, strong) UILabel *dateLabel;
@property(nonatomic, strong) NSDateFormatter *dateFormatter;
@property(nonatomic, strong) NSDate *minimumDate;
@property(nonatomic, strong) NSArray *disabledDates;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.calendarView.delegate = self;
    self.calendarView.onlyShowCurrentMonth = NO;
    self.calendarView.adaptHeightToNumberOfWeeksInMonth = YES;
    self.dateLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, CGRectGetMaxY(self.calendarView .frame) + 4, self.view.bounds.size.width, 24)];
    [self.view addSubview:self.dateLabel];
    

}


#pragma mark - CKCalendarDelegate
- (void)calendar:(JYCalendarView *)calendar configureDateItem:(CKDateItem *)dateItem forDate:(NSDate *)date {
    // TODO: play with the coloring if we want to...
    if ([self dateIsDisabled:date]) {
        dateItem.backgroundColor = [UIColor redColor];
        dateItem.textColor = [UIColor whiteColor];
    }
}

- (BOOL)calendar:(JYCalendarView *)calendar willSelectDate:(NSDate *)date {
    //获取选择当天的单价
//    [self getPriceData:date];
    return ![self dateIsDisabled:date];
}

- (void)calendar:(JYCalendarView *)calendar didSelectDate:(NSDate *)date {
    self.dateLabel.text = [self.dateFormatter stringFromDate:date];
}

- (BOOL)calendar:(JYCalendarView *)calendar willChangeToMonth:(NSDate *)date {
    NSDateFormatter *formater = [[NSDateFormatter alloc] init];
    [formater setDateFormat:@"yyyy-MM-dd"];
//    self.month = [formater stringFromDate:date];
//    [self getTicketPerMonthData];
    
    if ([date laterDate:self.minimumDate] == date) {
        self.calendarView.backgroundColor = [UIColor whiteColor];
        return YES;
    } else {
        self.calendarView.backgroundColor = [UIColor whiteColor];
        return NO;
    }
}

- (void)calendar:(JYCalendarView *)calendar didLayoutInRect:(CGRect)frame {
    NSLog(@"calendar layout: %@", NSStringFromCGRect(frame));
}

- (void)calendarHeight:(CGFloat)height {
    self.calendarHeight.constant = height;
}

- (BOOL)dateIsDisabled:(NSDate *)date {
    for (NSDate *disabledDate in self.disabledDates) {
        if ([disabledDate isEqualToDate:date]) {
            return YES;
        }
    }
    return NO;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}


@end

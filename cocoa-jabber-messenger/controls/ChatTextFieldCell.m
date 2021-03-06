//
//  YFRoundedTextFieldCell.m
//  
//
//  Created by Stuart Tevendale on 06/09/2010.
//  Copyright 2010 Yellow Field Technologies Ltd. All rights reserved.
//

#import "ChatTextFieldCell.h"

@implementation ChatTextFieldCell

- (void) drawInteriorWithFrame:(NSRect) cellFrame inView:(NSView*) controlView 
{
    BOOL isFocused = NO;
    
    if (([[controlView window] firstResponder] == controlView) && 
        [[controlView window] isMainWindow] &&
        [[controlView window] isKeyWindow]) {
        isFocused = YES;
    } else {
        isFocused = NO;
    }

    NSAttributedString* timeStamp = [self attributedTimeStampStringFromDate:messageTime];
    NSRect textRect = [self textRectFromCellFrame:cellFrame withMinimumWidth:100];
        
    NSRect bpRect = textRect;
    bpRect.origin.y += 5;
    bpRect.size.width += 10;
    bpRect.size.height -= 10;

    [self drawRect:bpRect withIsKeyWindow:isFocused];
    
    NSRect timeStampRect = textRect;
    timeStampRect.origin.y += (timeStampRect.size.height-15);
    //timeStampRect.size.width -= 10;
    [timeStamp drawInRect:timeStampRect];
    
    [super drawInteriorWithFrame:textRect inView:controlView];

}

@end

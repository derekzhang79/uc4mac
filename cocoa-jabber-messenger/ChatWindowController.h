//
//  ChatWindowController.h
//  Ta
//
//  Created by Sangeun Kim on 3/13/11.
//  Copyright 2011 NHN Corporation. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class MessageItem;
@class XMPPSession;
@class HistoryWindowController;
@interface ChatWindowController : NSWindowController< NSTableViewDataSource, NSTableViewDelegate> 
{
	IBOutlet NSTableView* chatListCtrl;
	IBOutlet NSTextFieldCell* msgToSend;
	IBOutlet NSImageView* profileImageView;
	IBOutlet NSTextField* commentCtrl;
    IBOutlet NSTextField* targetNameField;
    IBOutlet NSTextField* targetJidField;
	NSMutableArray*	messageArray;
	NSImage* targetImage;
	NSImage* myImage;
    NSString* targetName;
    NSString* targetJid;
    XMPPSession* session;
    HistoryWindowController* historyWindowController;
}

@property (assign) XMPPSession* session;
@property (nonatomic, retain) NSImage* targetImage;
@property (nonatomic, retain) NSImage* myImage;
@property (nonatomic, retain) NSString* targetName;
@property (nonatomic, retain) NSString* targetJid;

- (void) registerSession:(XMPPSession*) session;
- (void) onMessageReceived:(MessageItem*) msg;
- (IBAction) send:(id) sender;
- (IBAction) copy:(id) sender;
- (IBAction) showHistory:(id) sender;
//-(IBAction)sendMyLocation:(id)sender;
//-(MessageItem*) findItemByMessageKey:(long long)key;

@end
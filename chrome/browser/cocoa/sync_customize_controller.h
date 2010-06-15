// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_COCOA_SYNC_CUSTOMIZE_CONTROLLER_H_
#define CHROME_BROWSER_COCOA_SYNC_CUSTOMIZE_CONTROLLER_H_

#import <Cocoa/Cocoa.h>

#include "base/cocoa_protocols_mac.h"
#include "chrome/browser/sync/syncable/model_type.h"

class ProfileSyncService;

// A window controller for the sheet that allows the user to customize
// their sync data types.
@interface SyncCustomizeController : NSWindowController <NSWindowDelegate> {
 @private
  ProfileSyncService* syncService_;  // weak

  IBOutlet NSTextField* customizeSyncDescriptionTextField_;

  // The member variables below are connected to the dialog with KVO.

  // The registered flags indicate which model types are enabled for
  // syncing.
  BOOL bookmarksRegistered_;
  BOOL preferencesRegistered_;
  BOOL autofillRegistered_;
  BOOL themesRegistered_;
  BOOL extensionsRegistered_;

  // The preferred flags indicate which model types the user would
  // like to sync.
  BOOL bookmarksPreferred_;
  BOOL preferencesPreferred_;
  BOOL autofillPreferred_;
  BOOL themesPreferred_;
  BOOL extensionsPreferred_;
}

// syncService cannot be NULL.
- (id)initWithProfileSyncService:(ProfileSyncService*)syncService;

// Run as a sheet modal to the given window.
- (void)runAsModalSheet:(NSWindow*)parentWindow;

// End the sheet without saving the new preferred data types.
- (IBAction)endSheetWithCancel:(id)sender;

// Save the new preferred data types and end the sheet.
- (IBAction)endSheetWithOK:(id)sender;

// Properties for bindings.
@property (nonatomic, assign) BOOL bookmarksRegistered;
@property (nonatomic, assign) BOOL preferencesRegistered;
@property (nonatomic, assign) BOOL autofillRegistered;
@property (nonatomic, assign) BOOL themesRegistered;
@property (nonatomic, assign) BOOL extensionsRegistered;

@property (nonatomic, assign) BOOL bookmarksPreferred;
@property (nonatomic, assign) BOOL preferencesPreferred;
@property (nonatomic, assign) BOOL autofillPreferred;
@property (nonatomic, assign) BOOL themesPreferred;
@property (nonatomic, assign) BOOL extensionsPreferred;

@property (nonatomic, readonly) BOOL okEnabled;

@end

#endif  // CHROME_BROWSER_COCOA_SYNC_CUSTOMIZE_CONTROLLER_H_

//
//	HomebrewController.h
//	Cakebrew – The Homebrew GUI App for OS X
//
//	Created by Vincent Saluzzo on 06/12/11.
//	Copyright (c) 2014 Bruno Philipe. All rights reserved.
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>
#import "BPFormula.h"
#import "DMSplitView.h"
#import "BPInsetShadowView.h"
#import "BPFormulaeTableView.h"
#import "BPFormulaPopoverViewController.h"
#import "BPSideBarController.h"
#import "Frameworks/PXSourceList.framework/Headers/PXSourceList.h"

typedef NS_ENUM(NSUInteger, BPWindowOperation) {
	kBPWindowOperationInstall,
	kBPWindowOperationUninstall,
	kBPWindowOperationUpgrade,
	kBPWindowOperationTap,
	kBPWindowOperationUntap
};

@class DMSplitView;
@class BPInsetShadowView;
@class BPUpdateDoctorController;

@interface BPHomebrewViewController : NSViewController

@property (assign) IBOutlet PXSourceList           *outlineView_sidebar;

@property (weak) IBOutlet BPSideBarController      *sidebarController;
@property (weak) IBOutlet BPFormulaeTableView      *tableView_formulae;
@property (weak) IBOutlet NSScrollView             *scrollView_formulae;
@property (weak) IBOutlet DMSplitView              *splitView;
@property (weak) IBOutlet NSTabView                *tabView;
@property (weak) IBOutlet NSTextField              *label_information;
@property (weak) IBOutlet BPInsetShadowView        *view_disablerLock;
@property (weak) IBOutlet NSToolbar                *toolbar;
@property (weak) IBOutlet NSSearchField            *searchField;
@property (weak) IBOutlet NSMenu                   *menu_formula;

@property IBOutlet NSToolbarItem *toolbarButton_formulaInfo;
@property IBOutlet NSToolbarItem *toolbarButton_installUninstall;

// Cocoa bindings
@property (strong, nonatomic) NSString *formulaMenuTitle;
@property BOOL enableUpgradeFormulasMenu;

@property (weak) BPFormula *currentFormula;

- (void)prepareFormulae:(NSArray*)formulae forOperation:(BPWindowOperation)operation withOptions:(NSArray*)options;

- (IBAction)showFormulaInfo:(id)sender;
- (IBAction)installUninstallUpdate:(id)sender;
- (IBAction)installFormulaWithOptions:(id)sender;
- (IBAction)upgradeSelectedFormulae:(id)sender;
- (IBAction)upgradeAllOutdatedFormulae:(id)sender;
- (IBAction)updateHomebrew:(id)sender;
- (IBAction)openSelectedFormulaWebsite:(id)sender;
- (IBAction)searchFormulasFieldDidChange:(id)sender;
- (IBAction)beginFormulaSearch:(id)sender;

@end
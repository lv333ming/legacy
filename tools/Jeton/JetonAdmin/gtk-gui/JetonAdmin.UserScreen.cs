// ------------------------------------------------------------------------------
//  <autogenerated>
//      This code was generated by a tool.
//      
// 
//      Changes to this file may cause incorrect behavior and will be lost if 
//      the code is regenerated.
//  </autogenerated>
// ------------------------------------------------------------------------------

namespace JetonAdmin {
    
    
    public partial class UserScreen {
        
        private Gtk.HPaned hpaned1;
        
        private Gtk.VBox vbox2;
        
        private Gtk.Label label2;
        
        private Gtk.ScrolledWindow GtkScrolledWindow;
        
        private Gtk.NodeView cardListView;
        
        private Gtk.HButtonBox hbuttonbox1;
        
        private Gtk.Button button1;
        
        private Gtk.Button cardDeleteBtn;
        
        private Gtk.VBox vbox6;
        
        private Gtk.Label label12;
        
        private Gtk.Table table1;
        
        private Gtk.Entry cardCreditEntry;
        
        private Gtk.Entry cardEscrowEntry;
        
        private Gtk.Entry cardIdEntry;
        
        private Gtk.Entry cardNameEntry;
        
        private Gtk.ScrolledWindow GtkScrolledWindow1;
        
        private Gtk.NodeView nodeview3;
        
        private Gtk.Label label10;
        
        private Gtk.Label label11;
        
        private Gtk.Label label3;
        
        private Gtk.Label label4;
        
        private Gtk.Label label6;
        
        private Gtk.Label label9;
        
        private Gtk.VBox vbox3;
        
        private Gtk.CheckButton cardPermLaborant;
        
        private Gtk.CheckButton cardRoleDoor;
        
        private Gtk.CheckButton cardPermEscrow;
        
        private Gtk.CheckButton cardPermCreator;
        
        private Gtk.CheckButton cardPermGod;
        
        private Gtk.HButtonBox hbuttonbox2;
        
        private Gtk.HButtonBox hbuttonbox3;
        
        private Gtk.HButtonBox hbuttonbox4;
        
        private Gtk.HButtonBox hbuttonbox5;
        
        private Gtk.HButtonBox hbuttonbox6;
        
        private Gtk.HButtonBox hbuttonbox7;
        
        private Gtk.Button writeToCardBtn;
        
        private Gtk.Button undoBtn;
        
        private Gtk.Button saveBtn;
        
        private Gtk.HButtonBox hbuttonbox8;
        
        protected virtual void Build() {
            Stetic.Gui.Initialize(this);
            // Widget JetonAdmin.UserScreen
            Stetic.BinContainer.Attach(this);
            this.Name = "JetonAdmin.UserScreen";
            // Container child JetonAdmin.UserScreen.Gtk.Container+ContainerChild
            this.hpaned1 = new Gtk.HPaned();
            this.hpaned1.CanFocus = true;
            this.hpaned1.Name = "hpaned1";
            this.hpaned1.Position = 221;
            // Container child hpaned1.Gtk.Paned+PanedChild
            this.vbox2 = new Gtk.VBox();
            this.vbox2.Name = "vbox2";
            this.vbox2.Spacing = 6;
            // Container child vbox2.Gtk.Box+BoxChild
            this.label2 = new Gtk.Label();
            this.label2.Name = "label2";
            this.label2.Xalign = 0F;
            this.label2.LabelProp = Mono.Unix.Catalog.GetString("Benutzer:");
            this.vbox2.Add(this.label2);
            Gtk.Box.BoxChild w1 = ((Gtk.Box.BoxChild)(this.vbox2[this.label2]));
            w1.Position = 0;
            w1.Expand = false;
            w1.Fill = false;
            // Container child vbox2.Gtk.Box+BoxChild
            this.GtkScrolledWindow = new Gtk.ScrolledWindow();
            this.GtkScrolledWindow.Name = "GtkScrolledWindow";
            this.GtkScrolledWindow.ShadowType = ((Gtk.ShadowType)(1));
            // Container child GtkScrolledWindow.Gtk.Container+ContainerChild
            this.cardListView = new Gtk.NodeView();
            this.cardListView.CanFocus = true;
            this.cardListView.Name = "cardListView";
            this.GtkScrolledWindow.Add(this.cardListView);
            this.vbox2.Add(this.GtkScrolledWindow);
            Gtk.Box.BoxChild w3 = ((Gtk.Box.BoxChild)(this.vbox2[this.GtkScrolledWindow]));
            w3.Position = 1;
            // Container child vbox2.Gtk.Box+BoxChild
            this.hbuttonbox1 = new Gtk.HButtonBox();
            this.hbuttonbox1.Homogeneous = true;
            // Container child hbuttonbox1.Gtk.ButtonBox+ButtonBoxChild
            this.button1 = new Gtk.Button();
            this.button1.CanFocus = true;
            this.button1.Name = "button1";
            this.button1.UseStock = true;
            this.button1.UseUnderline = true;
            this.button1.Label = "gtk-add";
            this.hbuttonbox1.Add(this.button1);
            Gtk.ButtonBox.ButtonBoxChild w4 = ((Gtk.ButtonBox.ButtonBoxChild)(this.hbuttonbox1[this.button1]));
            w4.Expand = false;
            w4.Fill = false;
            // Container child hbuttonbox1.Gtk.ButtonBox+ButtonBoxChild
            this.cardDeleteBtn = new Gtk.Button();
            this.cardDeleteBtn.CanFocus = true;
            this.cardDeleteBtn.Name = "cardDeleteBtn";
            this.cardDeleteBtn.UseStock = true;
            this.cardDeleteBtn.UseUnderline = true;
            this.cardDeleteBtn.Label = "gtk-remove";
            this.hbuttonbox1.Add(this.cardDeleteBtn);
            Gtk.ButtonBox.ButtonBoxChild w5 = ((Gtk.ButtonBox.ButtonBoxChild)(this.hbuttonbox1[this.cardDeleteBtn]));
            w5.Position = 1;
            w5.Expand = false;
            w5.Fill = false;
            this.vbox2.Add(this.hbuttonbox1);
            Gtk.Box.BoxChild w6 = ((Gtk.Box.BoxChild)(this.vbox2[this.hbuttonbox1]));
            w6.Position = 2;
            w6.Expand = false;
            w6.Fill = false;
            w6.Padding = ((uint)(5));
            this.hpaned1.Add(this.vbox2);
            Gtk.Paned.PanedChild w7 = ((Gtk.Paned.PanedChild)(this.hpaned1[this.vbox2]));
            w7.Resize = false;
            // Container child hpaned1.Gtk.Paned+PanedChild
            this.vbox6 = new Gtk.VBox();
            this.vbox6.Name = "vbox6";
            this.vbox6.Spacing = 6;
            // Container child vbox6.Gtk.Box+BoxChild
            this.label12 = new Gtk.Label();
            this.label12.Name = "label12";
            this.label12.LabelProp = Mono.Unix.Catalog.GetString("Details zur gewählten Karte:");
            this.vbox6.Add(this.label12);
            Gtk.Box.BoxChild w8 = ((Gtk.Box.BoxChild)(this.vbox6[this.label12]));
            w8.Position = 0;
            w8.Expand = false;
            w8.Fill = false;
            // Container child vbox6.Gtk.Box+BoxChild
            this.table1 = new Gtk.Table(((uint)(6)), ((uint)(2)), false);
            this.table1.Name = "table1";
            this.table1.RowSpacing = ((uint)(6));
            this.table1.ColumnSpacing = ((uint)(6));
            this.table1.BorderWidth = ((uint)(9));
            // Container child table1.Gtk.Table+TableChild
            this.cardCreditEntry = new Gtk.Entry();
            this.cardCreditEntry.CanFocus = true;
            this.cardCreditEntry.Name = "cardCreditEntry";
            this.cardCreditEntry.IsEditable = true;
            this.cardCreditEntry.InvisibleChar = '●';
            this.table1.Add(this.cardCreditEntry);
            Gtk.Table.TableChild w9 = ((Gtk.Table.TableChild)(this.table1[this.cardCreditEntry]));
            w9.TopAttach = ((uint)(3));
            w9.BottomAttach = ((uint)(4));
            w9.LeftAttach = ((uint)(1));
            w9.RightAttach = ((uint)(2));
            w9.XOptions = ((Gtk.AttachOptions)(4));
            w9.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.cardEscrowEntry = new Gtk.Entry();
            this.cardEscrowEntry.CanFocus = true;
            this.cardEscrowEntry.Name = "cardEscrowEntry";
            this.cardEscrowEntry.IsEditable = true;
            this.cardEscrowEntry.InvisibleChar = '●';
            this.table1.Add(this.cardEscrowEntry);
            Gtk.Table.TableChild w10 = ((Gtk.Table.TableChild)(this.table1[this.cardEscrowEntry]));
            w10.TopAttach = ((uint)(4));
            w10.BottomAttach = ((uint)(5));
            w10.LeftAttach = ((uint)(1));
            w10.RightAttach = ((uint)(2));
            w10.XOptions = ((Gtk.AttachOptions)(4));
            w10.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.cardIdEntry = new Gtk.Entry();
            this.cardIdEntry.CanFocus = true;
            this.cardIdEntry.Name = "cardIdEntry";
            this.cardIdEntry.IsEditable = false;
            this.cardIdEntry.InvisibleChar = '●';
            this.table1.Add(this.cardIdEntry);
            Gtk.Table.TableChild w11 = ((Gtk.Table.TableChild)(this.table1[this.cardIdEntry]));
            w11.LeftAttach = ((uint)(1));
            w11.RightAttach = ((uint)(2));
            w11.XOptions = ((Gtk.AttachOptions)(4));
            w11.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.cardNameEntry = new Gtk.Entry();
            this.cardNameEntry.CanFocus = true;
            this.cardNameEntry.Name = "cardNameEntry";
            this.cardNameEntry.IsEditable = true;
            this.cardNameEntry.InvisibleChar = '●';
            this.table1.Add(this.cardNameEntry);
            Gtk.Table.TableChild w12 = ((Gtk.Table.TableChild)(this.table1[this.cardNameEntry]));
            w12.TopAttach = ((uint)(1));
            w12.BottomAttach = ((uint)(2));
            w12.LeftAttach = ((uint)(1));
            w12.RightAttach = ((uint)(2));
            w12.XOptions = ((Gtk.AttachOptions)(4));
            w12.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.GtkScrolledWindow1 = new Gtk.ScrolledWindow();
            this.GtkScrolledWindow1.Name = "GtkScrolledWindow1";
            this.GtkScrolledWindow1.ShadowType = ((Gtk.ShadowType)(1));
            // Container child GtkScrolledWindow1.Gtk.Container+ContainerChild
            this.nodeview3 = new Gtk.NodeView();
            this.nodeview3.CanFocus = true;
            this.nodeview3.Name = "nodeview3";
            this.GtkScrolledWindow1.Add(this.nodeview3);
            this.table1.Add(this.GtkScrolledWindow1);
            Gtk.Table.TableChild w14 = ((Gtk.Table.TableChild)(this.table1[this.GtkScrolledWindow1]));
            w14.TopAttach = ((uint)(5));
            w14.BottomAttach = ((uint)(6));
            w14.LeftAttach = ((uint)(1));
            w14.RightAttach = ((uint)(2));
            // Container child table1.Gtk.Table+TableChild
            this.label10 = new Gtk.Label();
            this.label10.Name = "label10";
            this.label10.LabelProp = Mono.Unix.Catalog.GetString("Treuhand-Konto:");
            this.table1.Add(this.label10);
            Gtk.Table.TableChild w15 = ((Gtk.Table.TableChild)(this.table1[this.label10]));
            w15.TopAttach = ((uint)(4));
            w15.BottomAttach = ((uint)(5));
            w15.XOptions = ((Gtk.AttachOptions)(4));
            w15.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.label11 = new Gtk.Label();
            this.label11.Name = "label11";
            this.label11.LabelProp = Mono.Unix.Catalog.GetString("Transaktionen:");
            this.table1.Add(this.label11);
            Gtk.Table.TableChild w16 = ((Gtk.Table.TableChild)(this.table1[this.label11]));
            w16.TopAttach = ((uint)(5));
            w16.BottomAttach = ((uint)(6));
            w16.XOptions = ((Gtk.AttachOptions)(4));
            w16.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.label3 = new Gtk.Label();
            this.label3.Name = "label3";
            this.label3.LabelProp = Mono.Unix.Catalog.GetString("Karten ID:");
            this.table1.Add(this.label3);
            Gtk.Table.TableChild w17 = ((Gtk.Table.TableChild)(this.table1[this.label3]));
            w17.XOptions = ((Gtk.AttachOptions)(4));
            w17.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.label4 = new Gtk.Label();
            this.label4.Name = "label4";
            this.label4.LabelProp = Mono.Unix.Catalog.GetString("Screen Name:");
            this.table1.Add(this.label4);
            Gtk.Table.TableChild w18 = ((Gtk.Table.TableChild)(this.table1[this.label4]));
            w18.TopAttach = ((uint)(1));
            w18.BottomAttach = ((uint)(2));
            w18.XOptions = ((Gtk.AttachOptions)(4));
            w18.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.label6 = new Gtk.Label();
            this.label6.Name = "label6";
            this.label6.LabelProp = Mono.Unix.Catalog.GetString("Rollen:");
            this.table1.Add(this.label6);
            Gtk.Table.TableChild w19 = ((Gtk.Table.TableChild)(this.table1[this.label6]));
            w19.TopAttach = ((uint)(2));
            w19.BottomAttach = ((uint)(3));
            w19.XOptions = ((Gtk.AttachOptions)(4));
            w19.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.label9 = new Gtk.Label();
            this.label9.Name = "label9";
            this.label9.LabelProp = Mono.Unix.Catalog.GetString("Guthaben:");
            this.table1.Add(this.label9);
            Gtk.Table.TableChild w20 = ((Gtk.Table.TableChild)(this.table1[this.label9]));
            w20.TopAttach = ((uint)(3));
            w20.BottomAttach = ((uint)(4));
            w20.XOptions = ((Gtk.AttachOptions)(4));
            w20.YOptions = ((Gtk.AttachOptions)(4));
            // Container child table1.Gtk.Table+TableChild
            this.vbox3 = new Gtk.VBox();
            this.vbox3.Name = "vbox3";
            this.vbox3.Spacing = 6;
            // Container child vbox3.Gtk.Box+BoxChild
            this.cardPermLaborant = new Gtk.CheckButton();
            this.cardPermLaborant.CanFocus = true;
            this.cardPermLaborant.Name = "cardPermLaborant";
            this.cardPermLaborant.Label = Mono.Unix.Catalog.GetString("Laborant");
            this.cardPermLaborant.DrawIndicator = true;
            this.cardPermLaborant.UseUnderline = true;
            this.vbox3.Add(this.cardPermLaborant);
            Gtk.Box.BoxChild w21 = ((Gtk.Box.BoxChild)(this.vbox3[this.cardPermLaborant]));
            w21.Position = 0;
            w21.Expand = false;
            w21.Fill = false;
            // Container child vbox3.Gtk.Box+BoxChild
            this.cardRoleDoor = new Gtk.CheckButton();
            this.cardRoleDoor.Sensitive = false;
            this.cardRoleDoor.CanFocus = true;
            this.cardRoleDoor.Name = "cardRoleDoor";
            this.cardRoleDoor.Label = Mono.Unix.Catalog.GetString("Türöffner");
            this.cardRoleDoor.DrawIndicator = true;
            this.cardRoleDoor.UseUnderline = true;
            this.vbox3.Add(this.cardRoleDoor);
            Gtk.Box.BoxChild w22 = ((Gtk.Box.BoxChild)(this.vbox3[this.cardRoleDoor]));
            w22.Position = 1;
            w22.Expand = false;
            w22.Fill = false;
            // Container child vbox3.Gtk.Box+BoxChild
            this.cardPermEscrow = new Gtk.CheckButton();
            this.cardPermEscrow.CanFocus = true;
            this.cardPermEscrow.Name = "cardPermEscrow";
            this.cardPermEscrow.Label = Mono.Unix.Catalog.GetString("Treuhänder");
            this.cardPermEscrow.DrawIndicator = true;
            this.cardPermEscrow.UseUnderline = true;
            this.vbox3.Add(this.cardPermEscrow);
            Gtk.Box.BoxChild w23 = ((Gtk.Box.BoxChild)(this.vbox3[this.cardPermEscrow]));
            w23.Position = 2;
            w23.Expand = false;
            w23.Fill = false;
            // Container child vbox3.Gtk.Box+BoxChild
            this.cardPermCreator = new Gtk.CheckButton();
            this.cardPermCreator.CanFocus = true;
            this.cardPermCreator.Name = "cardPermCreator";
            this.cardPermCreator.Label = Mono.Unix.Catalog.GetString("(Karten-) Erzeuger");
            this.cardPermCreator.DrawIndicator = true;
            this.cardPermCreator.UseUnderline = true;
            this.vbox3.Add(this.cardPermCreator);
            Gtk.Box.BoxChild w24 = ((Gtk.Box.BoxChild)(this.vbox3[this.cardPermCreator]));
            w24.Position = 3;
            w24.Expand = false;
            w24.Fill = false;
            // Container child vbox3.Gtk.Box+BoxChild
            this.cardPermGod = new Gtk.CheckButton();
            this.cardPermGod.CanFocus = true;
            this.cardPermGod.Name = "cardPermGod";
            this.cardPermGod.Label = Mono.Unix.Catalog.GetString("Gott");
            this.cardPermGod.Active = true;
            this.cardPermGod.DrawIndicator = true;
            this.cardPermGod.UseUnderline = true;
            this.vbox3.Add(this.cardPermGod);
            Gtk.Box.BoxChild w25 = ((Gtk.Box.BoxChild)(this.vbox3[this.cardPermGod]));
            w25.PackType = ((Gtk.PackType)(1));
            w25.Position = 4;
            w25.Expand = false;
            w25.Fill = false;
            this.table1.Add(this.vbox3);
            Gtk.Table.TableChild w26 = ((Gtk.Table.TableChild)(this.table1[this.vbox3]));
            w26.TopAttach = ((uint)(2));
            w26.BottomAttach = ((uint)(3));
            w26.LeftAttach = ((uint)(1));
            w26.RightAttach = ((uint)(2));
            w26.XOptions = ((Gtk.AttachOptions)(4));
            w26.YOptions = ((Gtk.AttachOptions)(4));
            this.vbox6.Add(this.table1);
            Gtk.Box.BoxChild w27 = ((Gtk.Box.BoxChild)(this.vbox6[this.table1]));
            w27.Position = 1;
            // Container child vbox6.Gtk.Box+BoxChild
            this.hbuttonbox2 = new Gtk.HButtonBox();
            this.hbuttonbox2.Name = "hbuttonbox2";
            this.hbuttonbox2.BorderWidth = ((uint)(6));
            this.vbox6.Add(this.hbuttonbox2);
            Gtk.Box.BoxChild w28 = ((Gtk.Box.BoxChild)(this.vbox6[this.hbuttonbox2]));
            w28.Position = 2;
            w28.Expand = false;
            w28.Fill = false;
            // Container child vbox6.Gtk.Box+BoxChild
            this.hbuttonbox3 = new Gtk.HButtonBox();
            this.hbuttonbox3.Name = "hbuttonbox3";
            this.vbox6.Add(this.hbuttonbox3);
            Gtk.Box.BoxChild w29 = ((Gtk.Box.BoxChild)(this.vbox6[this.hbuttonbox3]));
            w29.Position = 3;
            w29.Expand = false;
            w29.Fill = false;
            // Container child vbox6.Gtk.Box+BoxChild
            this.hbuttonbox4 = new Gtk.HButtonBox();
            this.hbuttonbox4.Name = "hbuttonbox4";
            this.vbox6.Add(this.hbuttonbox4);
            Gtk.Box.BoxChild w30 = ((Gtk.Box.BoxChild)(this.vbox6[this.hbuttonbox4]));
            w30.Position = 4;
            w30.Expand = false;
            w30.Fill = false;
            // Container child vbox6.Gtk.Box+BoxChild
            this.hbuttonbox5 = new Gtk.HButtonBox();
            this.hbuttonbox5.Name = "hbuttonbox5";
            this.vbox6.Add(this.hbuttonbox5);
            Gtk.Box.BoxChild w31 = ((Gtk.Box.BoxChild)(this.vbox6[this.hbuttonbox5]));
            w31.Position = 5;
            w31.Expand = false;
            w31.Fill = false;
            // Container child vbox6.Gtk.Box+BoxChild
            this.hbuttonbox6 = new Gtk.HButtonBox();
            this.hbuttonbox6.Name = "hbuttonbox6";
            this.vbox6.Add(this.hbuttonbox6);
            Gtk.Box.BoxChild w32 = ((Gtk.Box.BoxChild)(this.vbox6[this.hbuttonbox6]));
            w32.Position = 6;
            w32.Expand = false;
            w32.Fill = false;
            // Container child vbox6.Gtk.Box+BoxChild
            this.hbuttonbox7 = new Gtk.HButtonBox();
            this.hbuttonbox7.Name = "hbuttonbox7";
            this.hbuttonbox7.Spacing = 20;
            this.hbuttonbox7.BorderWidth = ((uint)(10));
            this.hbuttonbox7.LayoutStyle = ((Gtk.ButtonBoxStyle)(4));
            // Container child hbuttonbox7.Gtk.ButtonBox+ButtonBoxChild
            this.writeToCardBtn = new Gtk.Button();
            this.writeToCardBtn.CanFocus = true;
            this.writeToCardBtn.Name = "writeToCardBtn";
            this.writeToCardBtn.UseUnderline = true;
            // Container child writeToCardBtn.Gtk.Container+ContainerChild
            Gtk.Alignment w33 = new Gtk.Alignment(0.5F, 0.5F, 0F, 0F);
            // Container child GtkAlignment.Gtk.Container+ContainerChild
            Gtk.HBox w34 = new Gtk.HBox();
            w34.Spacing = 2;
            // Container child GtkHBox.Gtk.Container+ContainerChild
            Gtk.Image w35 = new Gtk.Image();
            w35.Pixbuf = Stetic.IconLoader.LoadIcon(this, "gtk-save", Gtk.IconSize.Menu, 16);
            w34.Add(w35);
            // Container child GtkHBox.Gtk.Container+ContainerChild
            Gtk.Label w37 = new Gtk.Label();
            w37.LabelProp = Mono.Unix.Catalog.GetString("Auf Karte schreiben");
            w37.UseUnderline = true;
            w34.Add(w37);
            w33.Add(w34);
            this.writeToCardBtn.Add(w33);
            this.hbuttonbox7.Add(this.writeToCardBtn);
            Gtk.ButtonBox.ButtonBoxChild w41 = ((Gtk.ButtonBox.ButtonBoxChild)(this.hbuttonbox7[this.writeToCardBtn]));
            w41.Expand = false;
            w41.Fill = false;
            // Container child hbuttonbox7.Gtk.ButtonBox+ButtonBoxChild
            this.undoBtn = new Gtk.Button();
            this.undoBtn.CanFocus = true;
            this.undoBtn.Name = "undoBtn";
            this.undoBtn.UseStock = true;
            this.undoBtn.UseUnderline = true;
            this.undoBtn.Label = "gtk-undo";
            this.hbuttonbox7.Add(this.undoBtn);
            Gtk.ButtonBox.ButtonBoxChild w42 = ((Gtk.ButtonBox.ButtonBoxChild)(this.hbuttonbox7[this.undoBtn]));
            w42.Position = 1;
            w42.Expand = false;
            w42.Fill = false;
            // Container child hbuttonbox7.Gtk.ButtonBox+ButtonBoxChild
            this.saveBtn = new Gtk.Button();
            this.saveBtn.CanFocus = true;
            this.saveBtn.Name = "saveBtn";
            this.saveBtn.UseStock = true;
            this.saveBtn.UseUnderline = true;
            this.saveBtn.Label = "gtk-save";
            this.hbuttonbox7.Add(this.saveBtn);
            Gtk.ButtonBox.ButtonBoxChild w43 = ((Gtk.ButtonBox.ButtonBoxChild)(this.hbuttonbox7[this.saveBtn]));
            w43.Position = 2;
            w43.Expand = false;
            w43.Fill = false;
            this.vbox6.Add(this.hbuttonbox7);
            Gtk.Box.BoxChild w44 = ((Gtk.Box.BoxChild)(this.vbox6[this.hbuttonbox7]));
            w44.Position = 7;
            w44.Expand = false;
            w44.Fill = false;
            // Container child vbox6.Gtk.Box+BoxChild
            this.hbuttonbox8 = new Gtk.HButtonBox();
            this.hbuttonbox8.Name = "hbuttonbox8";
            this.vbox6.Add(this.hbuttonbox8);
            Gtk.Box.BoxChild w45 = ((Gtk.Box.BoxChild)(this.vbox6[this.hbuttonbox8]));
            w45.Position = 8;
            w45.Expand = false;
            w45.Fill = false;
            this.hpaned1.Add(this.vbox6);
            this.Add(this.hpaned1);
            if ((this.Child != null)) {
                this.Child.ShowAll();
            }
            this.Show();
            this.button1.Clicked += new System.EventHandler(this.OnCardAdd);
            this.cardDeleteBtn.Clicked += new System.EventHandler(this.OnCardDelete);
            this.cardPermLaborant.Clicked += new System.EventHandler(this.OnRoleBtnClicked);
            this.cardRoleDoor.Clicked += new System.EventHandler(this.OnRoleBtnClicked);
            this.cardPermEscrow.Clicked += new System.EventHandler(this.OnRoleBtnClicked);
            this.cardPermCreator.Clicked += new System.EventHandler(this.OnRoleBtnClicked);
            this.cardPermGod.Clicked += new System.EventHandler(this.OnRoleBtnClicked);
            this.cardNameEntry.Changed += new System.EventHandler(this.OnChanged);
            this.cardEscrowEntry.Changed += new System.EventHandler(this.OnChanged);
            this.cardCreditEntry.Changed += new System.EventHandler(this.OnChanged);
            this.undoBtn.Clicked += new System.EventHandler(this.OnUndoClicked);
            this.saveBtn.Clicked += new System.EventHandler(this.OnSaveClicked);
        }
    }
}

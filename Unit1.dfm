object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 415
  ClientWidth = 334
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 56
    Width = 3
    Height = 13
  end
  object Label2: TLabel
    Left = 8
    Top = 8
    Width = 101
    Height = 13
    Caption = #1041#1091#1073#1085#1086#1074#1072'_'#1056#1048'-561220'
  end
  object Label3: TLabel
    Left = 256
    Top = 56
    Width = 51
    Height = 13
    Caption = #1050#1086#1085#1090#1072#1082#1090#1099
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 88
    Width = 315
    Height = 233
    AccessibleName = 'name'
    Header.AutoSizeIndex = 0
    TabOrder = 0
    OnAddToSelection = VirtualStringTree1Add
    OnGetText = VirtualStringTree1Text
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = 'id'
      end
      item
        Position = 1
        Text = 'name'
      end>
  end
  object Button1: TButton
    Left = 176
    Top = 327
    Width = 147
    Height = 65
    Caption = #1059#1076#1077#1083#1080#1090#1100' '#1074#1089#1105
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 327
    Width = 137
    Height = 65
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1082#1086#1085#1090#1072#1082#1090
    TabOrder = 2
    OnClick = Button2Click
  end
end

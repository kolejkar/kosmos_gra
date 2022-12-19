object map1: Tmap1
  Left = 458
  Top = 123
  Width = 1350
  Height = 807
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'map1'
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object workpanel: TPanel
    Left = 950
    Top = 0
    Width = 384
    Height = 768
    Align = alRight
    TabOrder = 0
    object info: TLabel
      Left = 8
      Top = 168
      Width = 6
      Height = 24
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object life: TLabel
      Left = 8
      Top = 8
      Width = 37
      Height = 29
      Caption = 'life'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 8
      Top = 752
      Width = 32
      Height = 13
      Caption = 'Label1'
    end
    object Attack: TBitBtn
      Left = 8
      Top = 56
      Width = 313
      Height = 49
      Caption = 'Atakuj'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = AttackClick
    end
    object MakeShip: TBitBtn
      Left = 8
      Top = 112
      Width = 313
      Height = 49
      Caption = 'Stw'#243'rz statek'
      Font.Charset = EASTEUROPE_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = MakeShipClick
    end
    object mini: TPanel
      Left = 8
      Top = 448
      Width = 300
      Height = 300
      BevelOuter = bvNone
      Color = clBlack
      TabOrder = 2
    end
  end
  object World: TPanel
    Left = 0
    Top = 0
    Width = 950
    Height = 768
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Space: TImage
      Left = 0
      Top = 0
      Width = 950
      Height = 768
      Align = alClient
      OnMouseDown = SpaceMouseDown
      OnMouseMove = BackSpaceMouseMove
      OnMouseUp = SpaceMouseUp
    end
    object Statistic: TLabel
      Left = 128
      Top = 128
      Width = 37
      Height = 13
      Caption = 'Statistic'
      Color = clMaroon
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clYellow
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      Visible = False
    end
  end
  object Drawing: TTimer
    Enabled = False
    Interval = 100
    OnTimer = DrawingTimer
  end
end

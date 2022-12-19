object Region: TRegion
  Left = 0
  Top = 0
  Width = 320
  Height = 240
  TabOrder = 0
  object DrawRegion: TTimer
    Interval = 10
    OnTimer = DrawRegionTimer
  end
end

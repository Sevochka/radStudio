object dm: Tdm
  OldCreateOrder = False
  Height = 407
  Width = 631
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=C:\Users\VD\Desktop\projradstudio\NotesDb\Notes.db'
      'DriverID=SQLite')
    LoginPrompt = False
    AfterConnect = FDConnection1AfterConnect
    BeforeConnect = FDConnection1BeforeConnect
    Left = 96
    Top = 72
  end
  object taNotes: TFDTable
    Connection = FDConnection1
    UpdateOptions.UpdateTableName = 'Notes'
    TableName = 'Notes'
    Left = 104
    Top = 152
    object taNotesCaption: TStringField
      FieldName = 'Caption'
      Origin = 'Caption'
      Required = True
      Size = 50
    end
    object taNotesPriority: TSmallintField
      FieldName = 'Priority'
      Origin = 'Priority'
      Required = True
    end
    object taNotesDetail: TStringField
      FieldName = 'Detail'
      Origin = 'Detail'
      Size = 500
    end
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'FMX'
    Left = 296
    Top = 184
  end
  object FDPhysSQLiteDriverLink1: TFDPhysSQLiteDriverLink
    Left = 392
    Top = 104
  end
end

object dm: Tdm
  OldCreateOrder = False
  Height = 466
  Width = 669
  object FDConnection1: TFDConnection
    Params.Strings = (
      'Database=C:\Users\Sevka\Desktop\labOnlineStore\ONLINESTORE.FDB'
      'User_Name=SYSDBA'
      'Password=masterkey'
      'CharacterSet=UTF8'
      'DriverID=FB')
    Connected = True
    Left = 552
    Top = 128
  end
  object FDGUIxWaitCursor1: TFDGUIxWaitCursor
    Provider = 'FMX'
    Left = 384
    Top = 344
  end
  object FDPhysFBDriverLink1: TFDPhysFBDriverLink
    Left = 504
    Top = 376
  end
  object spFeedbackIns: TFDStoredProc
    Connection = FDConnection1
    StoredProcName = 'FEEDBACK_INS'
    Left = 264
    Top = 344
    ParamData = <
      item
        Position = 1
        Name = 'FIO'
        DataType = ftWideString
        ParamType = ptInput
        Size = 70
      end
      item
        Position = 2
        Name = 'PHONE'
        DataType = ftWideString
        ParamType = ptInput
        Size = 15
      end
      item
        Position = 3
        Name = 'EMAIL'
        DataType = ftWideString
        ParamType = ptInput
        Size = 70
      end
      item
        Position = 4
        Name = 'NOTE'
        DataType = ftWideString
        ParamType = ptInput
        Size = 4000
      end>
  end
  object quCategory: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select'
      'c.id,'
      'c.name,'
      'c.image'
      'from category c'
      'order by c.sort_index, c.name')
    Left = 320
    Top = 216
    object quCategoryID: TIntegerField
      FieldName = 'ID'
      Origin = 'ID'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object quCategoryNAME: TWideStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Required = True
      Size = 70
    end
    object quCategoryIMAGE: TBlobField
      FieldName = 'IMAGE'
      Origin = 'IMAGE'
    end
  end
  object quProduct: TFDQuery
    Active = True
    Connection = FDConnection1
    SQL.Strings = (
      'select'
      'product.id,'
      'product.category_id,'
      'product.name,'
      'product.price,'
      'product.note,'
      'product.image'
      'from product product'
      'order by product.name')
    Left = 200
    Top = 200
    object quProductID: TIntegerField
      FieldName = 'ID'
      Origin = 'ID'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object quProductCATEGORY_ID: TIntegerField
      FieldName = 'CATEGORY_ID'
      Origin = 'CATEGORY_ID'
      Required = True
    end
    object quProductNAME: TWideStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Required = True
      Size = 70
    end
    object quProductPRICE: TFloatField
      FieldName = 'PRICE'
      Origin = 'PRICE'
      Required = True
    end
    object quProductNOTE: TWideStringField
      FieldName = 'NOTE'
      Origin = 'NOTE'
      Size = 4000
    end
    object quProductIMAGE: TBlobField
      FieldName = 'IMAGE'
      Origin = 'IMAGE'
    end
  end
end

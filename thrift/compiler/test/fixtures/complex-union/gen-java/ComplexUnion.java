/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.facebook.thrift.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

@SuppressWarnings({ "unused", "serial", "unchecked" })
public class ComplexUnion extends TUnion<ComplexUnion> implements Comparable<ComplexUnion> {
  public static boolean DEFAULT_PRETTY_PRINT = true;
  private static final TStruct STRUCT_DESC = new TStruct("ComplexUnion");
  private static final TField INT_VALUE_FIELD_DESC = new TField("intValue", TType.I64, (short)1);
  private static final TField STRING_VALUE_FIELD_DESC = new TField("stringValue", TType.STRING, (short)5);
  private static final TField INT_LIST_VALUE_FIELD_DESC = new TField("intListValue", TType.LIST, (short)2);
  private static final TField STRING_LIST_VALUE_FIELD_DESC = new TField("stringListValue", TType.LIST, (short)3);
  private static final TField TYPEDEF_VALUE_FIELD_DESC = new TField("typedefValue", TType.MAP, (short)9);
  private static final TField STRING_REF_FIELD_DESC = new TField("stringRef", TType.STRING, (short)14);

  public static final int INTVALUE = 1;
  public static final int STRINGVALUE = 5;
  public static final int INTLISTVALUE = 2;
  public static final int STRINGLISTVALUE = 3;
  public static final int TYPEDEFVALUE = 9;
  public static final int STRINGREF = 14;

  public static final Map<Integer, FieldMetaData> metaDataMap;
  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(INTVALUE, new FieldMetaData("intValue", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I64)));
    tmpMetaDataMap.put(STRINGVALUE, new FieldMetaData("stringValue", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    tmpMetaDataMap.put(INTLISTVALUE, new FieldMetaData("intListValue", TFieldRequirementType.DEFAULT, 
        new ListMetaData(TType.LIST, 
            new FieldValueMetaData(TType.I64))));
    tmpMetaDataMap.put(STRINGLISTVALUE, new FieldMetaData("stringListValue", TFieldRequirementType.DEFAULT, 
        new ListMetaData(TType.LIST, 
            new FieldValueMetaData(TType.STRING))));
    tmpMetaDataMap.put(TYPEDEFVALUE, new FieldMetaData("typedefValue", TFieldRequirementType.DEFAULT, 
        new MapMetaData(TType.MAP, 
            new FieldValueMetaData(TType.I16), 
            new FieldValueMetaData(TType.STRING))));
    tmpMetaDataMap.put(STRINGREF, new FieldMetaData("stringRef", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  public ComplexUnion() {
    super();
  }

  public ComplexUnion(int setField, Object value) {
    super(setField, value);
  }

  public ComplexUnion(ComplexUnion other) {
    super(other);
  }
  public ComplexUnion deepCopy() {
    return new ComplexUnion(this);
  }

  public static ComplexUnion intValue(long value) {
    ComplexUnion x = new ComplexUnion();
    x.setIntValue(value);
    return x;
  }

  public static ComplexUnion stringValue(String value) {
    ComplexUnion x = new ComplexUnion();
    x.setStringValue(value);
    return x;
  }

  public static ComplexUnion intListValue(List<Long> value) {
    ComplexUnion x = new ComplexUnion();
    x.setIntListValue(value);
    return x;
  }

  public static ComplexUnion stringListValue(List<String> value) {
    ComplexUnion x = new ComplexUnion();
    x.setStringListValue(value);
    return x;
  }

  public static ComplexUnion typedefValue(Map<Short,String> value) {
    ComplexUnion x = new ComplexUnion();
    x.setTypedefValue(value);
    return x;
  }

  public static ComplexUnion stringRef(String value) {
    ComplexUnion x = new ComplexUnion();
    x.setStringRef(value);
    return x;
  }


  @Override
  protected void checkType(short setField, Object value) throws ClassCastException {
    switch (setField) {
      case INTVALUE:
        if (value instanceof Long) {
          break;
        }
        throw new ClassCastException("Was expecting value of type Long for field 'intValue', but got " + value.getClass().getSimpleName());
      case STRINGVALUE:
        if (value instanceof String) {
          break;
        }
        throw new ClassCastException("Was expecting value of type String for field 'stringValue', but got " + value.getClass().getSimpleName());
      case INTLISTVALUE:
        if (value instanceof List) {
          break;
        }
        throw new ClassCastException("Was expecting value of type List<Long> for field 'intListValue', but got " + value.getClass().getSimpleName());
      case STRINGLISTVALUE:
        if (value instanceof List) {
          break;
        }
        throw new ClassCastException("Was expecting value of type List<String> for field 'stringListValue', but got " + value.getClass().getSimpleName());
      case TYPEDEFVALUE:
        if (value instanceof Map) {
          break;
        }
        throw new ClassCastException("Was expecting value of type Map<Short,String> for field 'typedefValue', but got " + value.getClass().getSimpleName());
      case STRINGREF:
        if (value instanceof String) {
          break;
        }
        throw new ClassCastException("Was expecting value of type String for field 'stringRef', but got " + value.getClass().getSimpleName());
      default:
        throw new IllegalArgumentException("Unknown field id " + setField);
    }
  }

  @Override
  public void read(TProtocol iprot) throws TException {
    setField_ = 0;
    value_ = null;
    iprot.readStructBegin(metaDataMap);
    TField field = iprot.readFieldBegin();
    if (field.type != TType.STOP)
    {
      value_ = readValue(iprot, field);
      if (value_ != null)
      {
        switch (field.id) {
          case INTVALUE:
            if (field.type == INT_VALUE_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case STRINGVALUE:
            if (field.type == STRING_VALUE_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case INTLISTVALUE:
            if (field.type == INT_LIST_VALUE_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case STRINGLISTVALUE:
            if (field.type == STRING_LIST_VALUE_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case TYPEDEFVALUE:
            if (field.type == TYPEDEF_VALUE_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
          case STRINGREF:
            if (field.type == STRING_REF_FIELD_DESC.type) {
              setField_ = field.id;
            }
            break;
        }
      }
      iprot.readFieldEnd();
      iprot.readFieldBegin();
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();
  }

  @Override
  protected Object readValue(TProtocol iprot, TField field) throws TException {
    switch (field.id) {
      case INTVALUE:
        if (field.type == INT_VALUE_FIELD_DESC.type) {
          Long intValue;
          intValue = iprot.readI64();
          return intValue;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case STRINGVALUE:
        if (field.type == STRING_VALUE_FIELD_DESC.type) {
          String stringValue;
          stringValue = iprot.readString();
          return stringValue;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case INTLISTVALUE:
        if (field.type == INT_LIST_VALUE_FIELD_DESC.type) {
          List<Long> intListValue;
          {
            TList _list0 = iprot.readListBegin();
            intListValue = new ArrayList<Long>(Math.max(0, _list0.size));
            for (int _i1 = 0; 
                 (_list0.size < 0) ? iprot.peekList() : (_i1 < _list0.size); 
                 ++_i1)
            {
              long _elem2;
              _elem2 = iprot.readI64();
              intListValue.add(_elem2);
            }
            iprot.readListEnd();
          }
          return intListValue;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case STRINGLISTVALUE:
        if (field.type == STRING_LIST_VALUE_FIELD_DESC.type) {
          List<String> stringListValue;
          {
            TList _list3 = iprot.readListBegin();
            stringListValue = new ArrayList<String>(Math.max(0, _list3.size));
            for (int _i4 = 0; 
                 (_list3.size < 0) ? iprot.peekList() : (_i4 < _list3.size); 
                 ++_i4)
            {
              String _elem5;
              _elem5 = iprot.readString();
              stringListValue.add(_elem5);
            }
            iprot.readListEnd();
          }
          return stringListValue;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case TYPEDEFVALUE:
        if (field.type == TYPEDEF_VALUE_FIELD_DESC.type) {
          Map<Short,String> typedefValue;
          {
            TMap _map6 = iprot.readMapBegin();
            typedefValue = new HashMap<Short,String>(Math.max(0, 2*_map6.size));
            for (int _i7 = 0; 
                 (_map6.size < 0) ? iprot.peekMap() : (_i7 < _map6.size); 
                 ++_i7)
            {
              short _key8;
              String _val9;
              _key8 = iprot.readI16();
              _val9 = iprot.readString();
              typedefValue.put(_key8, _val9);
            }
            iprot.readMapEnd();
          }
          return typedefValue;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      case STRINGREF:
        if (field.type == STRING_REF_FIELD_DESC.type) {
          String stringRef;
          stringRef = iprot.readString();
          return stringRef;
        } else {
          TProtocolUtil.skip(iprot, field.type);
          return null;
        }
      default:
        TProtocolUtil.skip(iprot, field.type);
        return null;
    }
  }

  @Override
  protected void writeValue(TProtocol oprot, short setField, Object value) throws TException {
    switch (setField) {
      case INTVALUE:
        Long intValue = (Long)getFieldValue();
        oprot.writeI64(intValue);
        return;
      case STRINGVALUE:
        String stringValue = (String)getFieldValue();
        oprot.writeString(stringValue);
        return;
      case INTLISTVALUE:
        List<Long> intListValue = (List<Long>)getFieldValue();
        {
          oprot.writeListBegin(new TList(TType.I64, intListValue.size()));
          for (long _iter10 : intListValue)          {
            oprot.writeI64(_iter10);
          }
          oprot.writeListEnd();
        }
        return;
      case STRINGLISTVALUE:
        List<String> stringListValue = (List<String>)getFieldValue();
        {
          oprot.writeListBegin(new TList(TType.STRING, stringListValue.size()));
          for (String _iter11 : stringListValue)          {
            oprot.writeString(_iter11);
          }
          oprot.writeListEnd();
        }
        return;
      case TYPEDEFVALUE:
        Map<Short,String> typedefValue = (Map<Short,String>)getFieldValue();
        {
          oprot.writeMapBegin(new TMap(TType.I16, TType.STRING, typedefValue.size()));
          for (Map.Entry<Short, String> _iter12 : typedefValue.entrySet())          {
            oprot.writeI16(_iter12.getKey());
            oprot.writeString(_iter12.getValue());
          }
          oprot.writeMapEnd();
        }
        return;
      case STRINGREF:
        String stringRef = (String)getFieldValue();
        oprot.writeString(stringRef);
        return;
      default:
        throw new IllegalStateException("Cannot write union with unknown field " + setField);
    }
  }

  @Override
  protected TField getFieldDesc(int setField) {
    switch (setField) {
      case INTVALUE:
        return INT_VALUE_FIELD_DESC;
      case STRINGVALUE:
        return STRING_VALUE_FIELD_DESC;
      case INTLISTVALUE:
        return INT_LIST_VALUE_FIELD_DESC;
      case STRINGLISTVALUE:
        return STRING_LIST_VALUE_FIELD_DESC;
      case TYPEDEFVALUE:
        return TYPEDEF_VALUE_FIELD_DESC;
      case STRINGREF:
        return STRING_REF_FIELD_DESC;
      default:
        throw new IllegalArgumentException("Unknown field id " + setField);
    }
  }

  @Override
  protected TStruct getStructDesc() {
    return STRUCT_DESC;
  }

  public long getIntValue() {
    if (getSetField() == INTVALUE) {
      return (Long)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'intValue' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setIntValue(long value) {
    setField_ = INTVALUE;
    value_ = value;
  }

  public String getStringValue() {
    if (getSetField() == STRINGVALUE) {
      return (String)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'stringValue' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setStringValue(String value) {
    if (value == null) throw new NullPointerException();
    setField_ = STRINGVALUE;
    value_ = value;
  }

  public List<Long> getIntListValue() {
    if (getSetField() == INTLISTVALUE) {
      return (List<Long>)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'intListValue' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setIntListValue(List<Long> value) {
    if (value == null) throw new NullPointerException();
    setField_ = INTLISTVALUE;
    value_ = value;
  }

  public List<String> getStringListValue() {
    if (getSetField() == STRINGLISTVALUE) {
      return (List<String>)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'stringListValue' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setStringListValue(List<String> value) {
    if (value == null) throw new NullPointerException();
    setField_ = STRINGLISTVALUE;
    value_ = value;
  }

  public Map<Short,String> getTypedefValue() {
    if (getSetField() == TYPEDEFVALUE) {
      return (Map<Short,String>)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'typedefValue' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setTypedefValue(Map<Short,String> value) {
    if (value == null) throw new NullPointerException();
    setField_ = TYPEDEFVALUE;
    value_ = value;
  }

  public String getStringRef() {
    if (getSetField() == STRINGREF) {
      return (String)getFieldValue();
    } else {
      throw new RuntimeException("Cannot get field 'stringRef' because union is currently set to " + getFieldDesc(getSetField()).name);
    }
  }

  public void setStringRef(String value) {
    if (value == null) throw new NullPointerException();
    setField_ = STRINGREF;
    value_ = value;
  }

  public boolean equals(Object other) {
    if (other instanceof ComplexUnion) {
      return equals((ComplexUnion)other);
    } else {
      return false;
    }
  }

  public boolean equals(ComplexUnion other) {
    return equalsNobinaryImpl(other);
  }

  @Override
  public int compareTo(ComplexUnion other) {
    return compareToImpl(other);
  }


  @Override
  public int hashCode() {
    return 0;
  }

  @Override
  public String toString() {
    return toString(DEFAULT_PRETTY_PRINT);
  }

  @Override
  public String toString(boolean prettyPrint) {
    return toString(1, prettyPrint);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    String indentStr = prettyPrint ? TBaseHelper.getIndentedString(indent) : "";
    String newLine = prettyPrint ? "\n" : "";
    String space = prettyPrint ? " " : "";
    StringBuilder sb = new StringBuilder("ComplexUnion");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    // Only print this field if it is the set field
    if (getSetField() == INTVALUE)
    {
      sb.append(indentStr);
      sb.append("intValue");
      sb.append(space);
      sb.append(":").append(space);
      sb.append(TBaseHelper.toString(this.getIntValue(), indent + 1, prettyPrint));
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == STRINGVALUE)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("stringValue");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getStringValue() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getStringValue(), indent + 1, prettyPrint));
      }
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == INTLISTVALUE)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("intListValue");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getIntListValue() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getIntListValue(), indent + 1, prettyPrint));
      }
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == STRINGLISTVALUE)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("stringListValue");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getStringListValue() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getStringListValue(), indent + 1, prettyPrint));
      }
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == TYPEDEFVALUE)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("typedefValue");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getTypedefValue() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getTypedefValue(), indent + 1, prettyPrint));
      }
      first = false;
    }
    // Only print this field if it is the set field
    if (getSetField() == STRINGREF)
    {
      if (!first) sb.append("," + newLine);
      sb.append(indentStr);
      sb.append("stringRef");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getStringRef() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getStringRef(), indent + 1, prettyPrint));
      }
      first = false;
    }
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }


}

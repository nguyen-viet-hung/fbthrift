/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic_swift_bean;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftUnion("MyUnion1")
public final class MyUnion1 {
    private final Object value;
    private final int id;
    private final String name;


    @ThriftConstructor
    public MyUnion1(final int i) {
        this.value = i;
        this.id = 1;
        this.name = "i";
    }

    @ThriftConstructor
    public MyUnion1(final double d) {
        this.value = d;
        this.id = 2;
        this.name = "d";
    }

    @ThriftField(value=1, name="i", requiredness=Requiredness.NONE)
    public int getI() {
        if (this.id != 1) {
            throw new IllegalStateException("Not a i element!");
        }
        return (int) value;
    }

    public boolean isSetI() {
        return this.id == 1;
    }

    @ThriftField(value=2, name="d", requiredness=Requiredness.NONE)
    public double getD() {
        if (this.id != 2) {
            throw new IllegalStateException("Not a d element!");
        }
        return (double) value;
    }

    public boolean isSetD() {
        return this.id == 2;
    }

    @ThriftUnionId
    public int getThriftId() {
        return this.id;
    }

    public String getThriftName() {
        return this.name;
    }

    @Override
    public String toString() {
        return toStringHelper(this)
            .add("value", value)
            .add("id", id)
            .add("name", name)
            .add("type", value == null ? "<null>" : value.getClass().getSimpleName())
            .toString();
    }
}

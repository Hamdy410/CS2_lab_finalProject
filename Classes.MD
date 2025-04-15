# Class Structure Documentation

---

## Class: `Item`
**Short Description:** Defines an item object  
**Data Members:**
- `name: QString`
- `category: QString`
- `quantity: int`
- `price: double`
- `supplier: QString`

**Member Functions:**
- `updateQuantity()`
- `getDetails()`
- `operator==()`
- `operator+=()`
- `operator-=()`

---

## Class: `Inventory`
**Short Description:** Contains all items  
**Data Members:**
- `items: unsorted_set<Item>`

**Member Functions:**
- `addItem()`
- `removeItem()`
- `searchItem()`
- `getLowStockItems()`
- `generateReport()`

---

## Class: `User`
**Short Description:** Defines a user object  
**Data Members:**
- `username: QString`
- `password: QString`
- `role: Role`

**Member Functions:**
- `login()`
- `changePassword()`
- `canManageUsers()`
- `canEditInventory()`
- `operator==()`

---

## Class: `Record`
**Short Description:** Facilitates record tracking  
**Data Members:**
- `item: Item`
- `user: User`
- `time: Time`

**Member Functions:**
- `appendToFile()`
- `displayHistory()`

---

## Class: `InventorySystem`
**Short Description:** Acts as a backend manager in the background  
**Data Members:**
- `users: unsorted_set<User>`
- `inventory: Inventory`
- `currentUser: User*`
- `records: Vector<Record>`

**Member Functions:**
- `load()`
- `save()`
- `addUser()`
- `deleteUser()`

---

## Enum: `Role`
**Short Description:** Enumerates to define users’ roles  
**Values:**
- `Admin`
- `Manager`
- `Staff`

**Member Functions:** N/A

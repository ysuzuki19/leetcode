use std::collections::HashMap;

struct User {
  start: String,
  time: i32
}

struct Record {
  sum: i32,
  count: i32,
}

struct UndergroundSystem {
  users: HashMap<i32, User>,
  records: HashMap<String, Record>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl UndergroundSystem {
  fn new() -> Self {
    Self {
      users: HashMap::new(),
      records: HashMap::new()
    }
  }

  fn get_key(&self, start_station: String, end_station: String) -> String {
    let mut key = start_station.clone();
    key.push('-');
    key.push_str(end_station.as_str());
    key
  }

  fn check_in(&mut self, id: i32, station_name: String, t: i32) {
    let user = User {start:station_name.clone(), time:t};
    self.users.insert(id, user);
  }

  fn check_out(&mut self, id: i32, station_name: String, t: i32) {
    let user = self.users.get(&id).unwrap();
    let key = self.get_key(user.start.clone(), station_name);
    let record = self.records.entry(key).or_insert(Record{sum:0,count:0});
    (*record).sum += (t - user.time);
    (*record).count += 1;
  }

  fn get_average_time(&self, start_station: String, end_station: String) -> f64 {
    let key = self.get_key(start_station, end_station);
    let record = self.records.get(&key).unwrap();

    ((*record).sum as f64) / ((*record).count as f64)
  }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * let obj = UndergroundSystem::new();
 * obj.check_in(id, stationName, t);
 * obj.check_out(id, stationName, t);
 * let ret_3: f64 = obj.get_average_time(startStation, endStation);
 */